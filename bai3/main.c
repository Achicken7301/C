#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
struct info {
  // Luu dia chi dau tien cua array
  int *arr;
  // Luu size cua array
  int size;
};

void maxValue(struct info *info) {
  int max = *(info->arr);
  int *ptr = info->arr;
  for (int i = 0; i < info->size; i++) {
    // printf("arr[%d]: %d\n", i, *(info->arr + i));
    if (max < *(ptr + i)) {
      max = *(ptr + i);
    }
  }
  printf("max: %d\n", max);
}

void swap2Value(int *i1, int *i2) {
  int temp = *i1;
  *i1 = *i2;
  *i2 = temp;
}

void min2Max(struct info *info) {
  int i, j;
  for (i = 0; i < info->size - 1; i++) {
    // Last i elements are already in place
    // printf("With arr[%d]: %d\n", i, info->arr[i]);
    for (j = 0; j < info->size - i - 1; j++) {
      if (info->arr[j] > info->arr[j + 1]) {
        swap2Value(&info->arr[j], &info->arr[j + 1]);
      }
    }
  }
  printf("min to max: ");
  for (int i = 0; i < info->size; i++) {
    printf("%d\t", info->arr[i]);
  }
  printf("\n");
}

void max2Min(struct info *info) {
  int i, j;
  for (i = 0; i < info->size - 1; i++) {
    // Last i elements are already in place
    // printf("With arr[%d]: %d\n", i, info->arr[i]);
    for (j = 0; j < info->size - i - 1; j++) {
      if (info->arr[j] < info->arr[j + 1]) {
        swap2Value(&info->arr[j], &info->arr[j + 1]);
      }
    }
  }
  printf("max to min: ");
  for (int i = 0; i < info->size; i++) {
    printf("%d\t", info->arr[i]);
  }
  printf("\n");
}

struct info *infoInput() {
  // Chua co dia chi?
  static struct info info;
  int *ptr;
  int size;

  printf("Kich thuoc mang arr la: ");
  scanf("%d", &size);

  ptr = (int *)malloc(size * sizeof(int));

  for (int i = 0; i < size; i++) {
    printf("Phan tu arr[%d] la: ", i);
    scanf("%d", ptr + i);
  }

  info.arr = ptr;
  info.size = size;

  return &info;
}

int main() {
  struct info *info;
  info = infoInput();
  int status = 0;
  int stop = 0;

  do {
    printf("Chon che do: ");
    scanf("%d", &status);
    switch (status) {
    case 0:
      info = infoInput();
      break;
    case 1:
      maxValue(info);
      break;
    case 2:
      min2Max(info);
      break;
    case 3:
      max2Min(info);
      break;
    case 4:
      stop = 1;
      break;
    default:
      printf("error\n");
    }

  } while (stop == 0);

  return 0;
}
