#include <stdio.h>

int odd[10];
int even[10];

void oddEven(int *ptr) {
  for (int i = 0; i < 10; i++) {
    // printf("arr[%d]: %d\n", i, ptr[i]);
    switch (ptr[i] % 2) {
    case 0:
      printf("number %d is added to even\n", ptr[i]);
      even[i] = ptr[i];
      goto label;
    case 1:
      printf("number %d is added to odd\n", ptr[i]);
      odd[i] = ptr[i];
      goto label;
    default:
      printf("error");
    }
  label:;
  }
}
int main() {
  int arr[10] = {8, 7, 0, 9, 1, 2, 5, 3, 6, 4};
  oddEven(arr);
  return 0;
}