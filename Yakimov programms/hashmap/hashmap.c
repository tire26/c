#include "hashmap.h"
#include <stdlib.h>
#include <string.h>

static size_t hash(char* str) {
  size_t hash = 5381;
  int c;
  while ((c = *str++)) {
    // hash[i] = hash[i-1] * 33 ^ str[i];
    hash = ((hash << 5) + hash) ^ c;
  }
  return hash;
}

hashmap *hashmap_create(size_t sz) {
  hashmap *m = malloc(sizeof(hashmap)+sizeof(hashmap_el*)*sz);
  m->size = sz;
  memset(m->buckets, 0, sizeof(hashmap_el*)*sz);
  return m;
}

void hashmap_free(hashmap *m) {
  for(size_t i = 0; i<m->size; ++i) {
    hashmap_el *el= m->buckets[i];
    while(el) {
      hashmap_el *t = el->next;
      free(el);
      el = t;
    }
  }
  free(m);
}

void hashmap_add(hashmap *m, char* key, int value) {
  size_t arr_idx = hash(key) % m->size;
  hashmap_el *el = malloc(sizeof(hashmap_el));
  el->key = key;
  el->value = value;
  el->next = m->buckets[arr_idx];
  m->buckets[arr_idx] = el;
}

bool hashmap_get(hashmap *m, char* key, int *value) {
  size_t arr_idx = hash(key) % m->size;
  hashmap_el *el = m->buckets[arr_idx];
  while(el) {
    if(strcmp(el->key, key) == 0) {
      if(value) {
        *value = el->value;
      }
      return true;
    }
    el = el->next;
  }
  return false;
}
