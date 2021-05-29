#include "list.h"
#include "stack.h"
#include "heap.h"
#include "huffman.h"
#include "hashmap.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>

void test_list() {
  list* l = list_create();
  char
    * t1 = "t1",
    * t2 = "t2",
    * t3 = "t3",
    * t4 = "t4",
    * t5 = "t5";
  list_elem* el1 = list_insert(l, t1, NULL);
  list_elem* el2 = list_insert(l, t2, el1);
  list_elem* el3 = list_insert(l, t3, el2);
  list_elem* el4 = list_insert(l, t4, el3);
  list_insert(l, t5, el4);
  list_elem *el = l->first;
  while(el) {
    printf("%s\n", (char*)el->data);
    el = el->next;
  }
  list_free(l);
}

void test_stack() {
  stack* s = stack_create(8);
  char * t[] = {"t1",
    "t2",
    "t3",
    "t4",
    "t5"};
  for(size_t i=0; i<5; ++i) {
    stack_push(s, t[i]);
  }
  printf("top: %s\n", (char*) stack_peek(s));
  while(stack_peek(s)) {
    char* t = stack_pop(s);
    printf("%s\n", t);
  }
  stack_free(s);
}

void test_heap() {
  heap* h = heap_create(8);
  char * t[] = {"t1",
    "t2",
    "t3",
    "t4",
    "t5"};
  for(size_t i=0; i<5; ++i) {
    heap_insert(h, -i-1, t[i]);
  }
  printf("max: %s\n", (char*) heap_peek(h));
  while(heap_peek(h)) {
    char* t = heap_extract(h);
    printf("%s\n", t);
  }
  heap_free(h);
}

unsigned char current_byte = 0;
unsigned char current_len = 0;

void write_bit(FILE *f, unsigned char bit) {
  current_byte = current_byte << 1;
  current_byte |= bit;
  ++current_len;
  if(current_len == 8) {
    fwrite(&current_byte, 1, 1, f);
    current_len = 0;
    current_byte = 0;
  }
}

void finalize(FILE *f) {
  current_byte = current_byte << (8-current_len);
  fwrite(&current_byte, 1, 1, f);
  current_len = 0;
  current_byte = 0;
}

char read_bit(FILE *f) {
  if(current_len == 0) {
    current_byte = fgetc(f);
    current_len = 8;
  }
  --current_len;
  if(current_byte & (1 << current_len)) {
    return '1';
  } else {
    return '0';
  }
}

void huf_encode(const char* ifn, const char* ofn) {
  FILE *f = fopen(ifn, "r");
  size_t freqs[NUM_CHAR] = {0};
  heap *frequency_heap = get_freq(f, freqs);
  htree *h = build_htree(frequency_heap);
  heap_free(frequency_heap);
  char codes[NUM_CHAR][NUM_CHAR+1] = {0};
  stack *prefix = stack_create(NUM_CHAR);
  build_codes(h, prefix, codes);
  htree_free(h);
  stack_free(prefix);
  for (size_t i = 0; i < NUM_CHAR; ++i) {
    if (codes[i][0] > 0) {
      printf("%02x : %s\n", (int)i, codes[i]);
    }
  }
  long int ifs = ftell(f);
  FILE *of = fopen(ofn, "w");
  fwrite(&ifs, sizeof(long int), 1, of);
  fwrite(freqs, sizeof(size_t), NUM_CHAR, of);
  fseek(f, 0, SEEK_SET);
  while(!feof(f)) {
    int r = fgetc(f);
    char *code = codes[r];
    while (*code != 0) {
      if(*code == '0') {
        write_bit(of, 0);
      } else {
        write_bit(of, 1);
      }
      ++code;
    }
  }
  finalize(of);
  fclose(f);
  fclose(of);
}

void huf_decode(const char* ifn, const char* ofn) {
  FILE *f = fopen(ifn, "r");
  long int ifs;
  size_t freqs[NUM_CHAR];
  fread(&ifs, sizeof(long int), 1, f);
  fread(freqs, sizeof(size_t), NUM_CHAR, f);
  heap *frequency_heap = build_heap(freqs);
  htree *h = build_htree(frequency_heap);
  heap_free(frequency_heap);
  char codes[NUM_CHAR][NUM_CHAR+1] = {0};
  stack *prefix = stack_create(NUM_CHAR);
  build_codes(h, prefix, codes);
  htree_free(h);
  stack_free(prefix);

  hashmap *m = hashmap_create(NUM_CHAR*2);
  for(size_t i = 0; i < NUM_CHAR; ++i) {
    if (codes[i][0] != 0) {
      hashmap_add(m, codes[i], i);
    }
  }

  FILE *of = fopen(ofn, "w");
  size_t ofs = 0;
  char code[NUM_CHAR+1] = {0};
  size_t code_len = 0;
  while(ofs < ifs) {
    code[code_len] = read_bit(f);
    ++code_len;
    int value;
    if(hashmap_get(m, code, &value)) {
      fwrite(&value, 1, 1, of);
      memset(code, 0, code_len);
      code_len = 0;
      ++ofs;
    }
  }
  hashmap_free(m);
  fclose(f);
  fclose(of);
}

int main(int argc, char *argv[]) {
  // test_list();
  // test_stack();
  // test_heap();
  if (argc != 4 || (strcmp(argv[1], "enc") != 0 && strcmp(argv[1], "dec") != 0)) {
    printf("Usage:\n\t%s (enc|dec) input_file output_file\n", argv[0]);
    return 1;
  }
  if(strcmp(argv[1], "enc") == 0) {
    huf_encode(argv[2], argv[3]);
  } else {
    huf_decode(argv[2], argv[3]);
  }
  return 0;
}
