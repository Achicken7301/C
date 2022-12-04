#include <malloc.h>
#include <stdio.h>

#define QUEUE_SIZE 5
int front = 0, rear = -1;
int isEmpty();
int isFull();
void enQueue();
void showQueue();
int deQueue();
int queue[QUEUE_SIZE];

int main(int argc, char const *argv[]) {
  enQueue(queue, 2);
  enQueue(queue, 10);
  enQueue(queue, 7);
  enQueue(queue, 9);
  enQueue(queue, 5);
  deQueue(queue);
  deQueue(queue);
  enQueue(queue, 3);
  showQueue();
  return 0;
}

int isFull() {
  if (rear == QUEUE_SIZE - 1) {
    return 1;
  } else {
    return 0;
  }
}

int isEmpty() {
  if (front > rear) {
    return 1;
  } else {
    return 0;
  }
}

void enQueue(int *queue, int value) {
  // check queue is full
  if (isFull()) {
    printf("queue is Full\n");
  } else {
    rear++;
    queue[rear] = value;
  }
}

// delete front
int deQueue(int *queue) {
  if (isEmpty()) {
    printf("Queue is empty\n");
    return -1;
  } else {
    int res = queue[front];
    queue[front] = '\0';
    front++;
    return res;
  }
}

void showQueue() {
  for (int queue_index = 0; queue_index < QUEUE_SIZE; queue_index++) {
    printf("%d \t", queue[queue_index]);
  }
  printf("\n");
}