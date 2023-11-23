#ifndef QUEUE
#define QUEUE

#include <stdbool.h>

typedef struct {
  void *internal;
} Queue;

Queue *queue_init();

void queue_deinit(Queue *self);

bool queue_is_empty(Queue *self);

void queue_print(Queue *self);

void queue_add(Queue *self, int val);

int queue_remove(Queue *self);

int queue_peek(Queue *self);

#endif
