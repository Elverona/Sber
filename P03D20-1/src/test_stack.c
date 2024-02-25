#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

struct stack *init(char val, float d) {
  struct stack *t = malloc(sizeof(struct stack));
  t->data = val;
  t->num = d;
  t->next = NULL;
  return t;
}

struct stack *push(struct stack *h, char val) {
  if (h != NULL) {
    struct stack *new_el = init(val, 0);
    new_el->next = h;
    h = new_el;
  } else {
    h = init(val, 0);
  }
  return h;
}

struct stack *push_num(struct stack *h, float val) {
  if (h != NULL) {
    struct stack *new_el = init('\0', val);
    new_el->next = h;
    h = new_el;
  } else {
    h = init('\0', val);
  }
  return h;
}

struct stack *pop(struct stack *h) {
  if (h != NULL) {
    struct stack *del = h;
    h = h->next;
    free(del);
  }
  return h;
}