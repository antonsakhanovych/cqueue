#include "./queue.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *data;
  size_t head_ind;
  size_t size;
  int cap;
} _Queue;

Queue *queue_init() {
  _Queue *internal = malloc(sizeof(_Queue));
  *internal =
      (_Queue){.cap = INITIAL_CAPACITY, .head_ind = 0, .size = 0, .data = NULL};
  internal->data = calloc(internal->cap, sizeof(int));
  Queue *self = malloc(sizeof(Queue));
  self->_internal = internal;
  return self;
}

bool queue_is_empty(Queue const *self) {
  _Queue *internal = self->_internal;
  return internal->size == 0;
}

void queue_print(Queue const *self) {
  _Queue *internal = self->_internal;
  printf("out <- [ ");
  for (size_t ind = internal->head_ind;
       ind < (internal->head_ind + internal->size); ind++) {
    printf("%d ", internal->data[ind % internal->cap]);
  }
  printf("] <- in\n");
}

void queue_add(Queue *self, int val) {
  _Queue *internal = self->_internal;
  if (internal->size == internal->cap) {
    return;
  }
  size_t add_ind = (internal->head_ind + internal->size) % internal->cap;
  internal->size += 1;
  internal->data[add_ind] = val;
}

int queue_remove(Queue *self) {
  _Queue *internal = self->_internal;
  size_t head_ind = internal->head_ind % internal->cap;
  int res = internal->data[head_ind];
  internal->head_ind += 1;
  internal->size -= 1;
  return res;
}

int queue_peek(Queue const *self) {
  _Queue const *internal = self->_internal;
  return internal->data[internal->head_ind % internal->cap];
}

void queue_deinit(Queue *self) {
  _Queue *internal = self->_internal;
  free(internal->data);
  free(internal);
  free(self);
};
