#include "./queue.h"
#include <stdio.h>

int main(void) {
  Queue *queue = queue_init();
  queue_add(queue, 1);
  queue_add(queue, 2);
  queue_add(queue, 3);
  queue_add(queue, 4);

  queue_print(queue);
  printf("\n");

  while (!queue_is_empty(queue)) {
    printf("Popped: %d\n", queue_remove(queue));
    queue_print(queue);
    printf("\n");
  }

  queue_deinit(queue);
}
