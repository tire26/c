#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct list_t {
  int value;
  struct list_t *next;
};
typedef struct list_t list;

/*
// проход по списку
while(listitem) {
  listitem = listitem->next;
}

// вставка после эл-та listitem
newitem->next = listitem->next;
listitem->next = newitem;

// добавление в начало
newitem->next = firstitem
firstitem = newitem
*/

list *merge(list *a, list *b) {
  list *i = a, *j = b, *k, *res;
  if (i->value < j->value) {
    k = i;
    i = i->next;
  } else {
    k = j;
    j = j->next;
  }
  res = k;
  while (i && j) {
    if (i->value < j->value) {
      k->next = i;
      k = i;
      i = i->next;
    } else {
      k->next = j;
      k = j;
      j = j->next;
    }
  }
  while (i) {
    k->next = i;
    k = i;
    i = i->next;
  }
  while (j) {
    k->next = j;
    k = j;
    j = j->next;
  }
  return res;
}

// O(n log n)
list *mergesort(list* lst) {
  if (!lst->next) return lst;
  list *k = lst, *l = lst;
  bool flipflop = false;
  while(k->next) { // k -- не последний
    k = k->next;
    if(flipflop) l = l->next;
    flipflop = !flipflop;
  }
  k = l->next;
  l->next = NULL;
  list* a = mergesort(lst);
  list* b = mergesort(k);
  return merge(a, b); // O(len)
}

int main() {
  const size_t len = 101;
  list a[len];
  for (size_t i = 0; i < len-1; ++i) {
    a[i].value = rand() % 1000;
    a[i].next = &a[i+1];
  }
  a[len-1].value = rand() % 1000;
  a[len-1].next = NULL;
  list* res = mergesort(&a[0]);
  list* i = res;
  while(i) {
    printf("%d\n", i->value);
    i = i->next;
  }
  return 0;
}
