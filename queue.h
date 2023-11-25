#ifndef QUEUE
#define QUEUE

#define INITIAL_CAPACITY 10

#include <stdbool.h>

typedef struct {
  void *_internal;
} Queue;

Queue *queue_init();

void queue_deinit(Queue *self);

bool queue_is_empty(Queue const *self);

void queue_print(Queue const *self);

void queue_add(Queue *self, int val);

int queue_remove(Queue *self);

int queue_peek(Queue const *self);

#endif
