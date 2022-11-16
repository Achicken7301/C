#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node *next;
} Node;

Node *createNote(int value) {
  Node *temp;
  temp = (Node *)malloc(sizeof(Node));
  temp->value = value;
  temp->next = NULL;
  return temp;
}

void addAtTail(Node **head, int value) {
  Node *temp, *ptr;
  temp = createNote(value);
  // if is_node_1
  if (*head == NULL) {
    *head = temp;
  } else {
    // find ptr->next = NULL
    ptr = *head;
    while (ptr->next != NULL) {
      ptr = ptr->next;
    }
    ptr->next = temp;
  }
}

int getNode(Node **head, int node_number) {
  Node *ptr = *head;
  int flag = 0;
  for (int i = 0; i < node_number; i++) {
    ptr = ptr->next;
    if (ptr == NULL) {
      return -1;
    }
  }
  return ptr->value;
}

void addAtHead(Node **head, int value) {
  Node *temp, *ptr;
  temp = createNote(value);
  // check 1st condition
  if (*head == NULL) {
    *head = temp;
  } else {
    temp->next = *head;
    *head = temp;
  }
}

void addAtIndex(Node **head, int value) {
  
  
}

int main(int argc, char const *argv[]) {
  Node *node1 = NULL;
  // pass by reference
  addAtHead(&node1, 2);
  addAtHead(&node1, 10);
  addAtTail(&node1, 7);
  addAtHead(&node1, 12);
  addAtTail(&node1, 1);
  addAtHead(&node1, 9);
  // Get Node
  for (int i = 0; i < 6; i++) {
    printf("%d\n", getNode(&node1, i));
  }
  return 0;
}
