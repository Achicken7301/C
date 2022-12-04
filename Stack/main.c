#include <malloc.h>
#include <stdio.h>

#define MAX_SIZE 5

int stack[MAX_SIZE];
void pushStack(); // add value
int popStack();   // delete last value and return
int isEmpty();
int isFull();
int index_stack = 0;
void showStack(int *stack);

int main(int argc, char const *argv[]) {
  pushStack(stack, 5);
  pushStack(stack, 6);
  pushStack(stack, 2);
  popStack(stack);
  pushStack(stack, 10);
  showStack(stack);
  return 0;
}

int isFull() {
  if (index_stack > MAX_SIZE - 1) {
    return 1;
  } else {
    return 0;
  }
}

int isEmpty() {
  if (index_stack < 0) {
    return 1;
  } else {
    return 0;
  }
}

void pushStack(int *stack, int value) {
  if (isFull()) {
    printf("Stack is full");
  } else {
    stack[index_stack] = value;
    index_stack++;
  }
}

int popStack(int *stack) {
  if (isEmpty()) {
    printf("Stack is empty");
    return 0;
  } else {
    int res = stack[index_stack - 1];
    stack[index_stack - 1] = 0;
    index_stack--;
    return res;
  }
}

void showStack(int *stack) {
  for (int i = 0; i < MAX_SIZE; i++) {
    printf("%d\t", stack[i]);
  }
  printf("\n");
}