#include "./queue.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _node _Node;

struct _node {
  int val;
  _Node *next;
};

typedef struct {
  _Node *head;
  _Node *tail;
} _Queue;

Queue *queue_init() {
  _Queue *internal = malloc(sizeof(_Queue));
  internal->head = NULL;
  internal->tail = NULL;
  Queue *self = malloc(sizeof(Queue));
  self->internal = internal;
  return self;
}

bool queue_is_empty(Queue *self) {
  _Queue *internal = self->internal;
  if (internal->head == NULL)
    return true;
  else
    return false;
}

void queue_print(Queue *self) {
  _Queue *internal = self->internal;
  _Node *curr = internal->head;
  printf("out <- [ ");
  while (curr != NULL) {
    printf("%d ", curr->val);
    curr = curr->next;
  }
  printf("] <- in\n");
}

void queue_add(Queue *self, int val) {
  _Queue *internal = self->internal;
  _Node *new_node = malloc(sizeof(_Node));
  *new_node = (_Node){.val = val, .next = NULL};
  if (internal->tail != NULL) {
    internal->tail->next = new_node;
  }
  internal->tail = new_node;
  if (internal->head == NULL) {
    internal->head = new_node;
  }
}

int queue_remove(Queue *self) {
  _Queue *internal = self->internal;
  _Node *node = internal->head;
  int res = node->val;
  if (internal->head == internal->tail) {
    internal->tail = NULL;
  }
  internal->head = node->next;
  free(node);
  return res;
}

int queue_peek(Queue *self) {
  _Queue *internal = self->internal;
  return internal->head->val;
}

void queue_deinit(Queue *self) {
  _Queue *internal = self->internal;
  _Node *curr = internal->head;
  while (curr != NULL) {
    _Node *temp = curr->next;
    free(curr);
    curr = temp;
  }
  internal->head = internal->tail = NULL;
  free(internal);
  free(self);
}
