#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { RED, YELLOW, GREEN } SOCK;
typedef struct {
  // Luu dia chi dau tien cua mang
  SOCK *ptr;
  // Luu kich thuoc cua mang
  int size;
} BOX;

void infoInput(BOX *info) {
  char sock[6];

  printf("Number of socks: ");
  scanf("%d", &info->size);

  info->ptr = (SOCK *)malloc(info->size * sizeof(SOCK));
  for (int i = 0; i < info->size; i++) {
  label:
    printf("Sock #[%d] is: ", i);
    scanf("%s", sock);

    if (strcmp((char *)"RED", sock) == 0) {
      info->ptr[i] = RED;
    } else if (strcmp((char *)"YELLOW", sock) == 0) {
      info->ptr[i] = YELLOW;
    } else if (strcmp((char *)"GREEN", sock) == 0) {
      info->ptr[i] = GREEN;
    } else {
      printf("ERROR\n");
      goto label;
    }
  }
}

void countSocks(BOX *info) {
  int counter_red = 0;
  int counter_yellow = 0;
  int counter_green = 0;

  for (int i = 0; i < info->size; i++) {
    switch (info->ptr[i]) {
    case RED:
      counter_red++;
      goto label;
    case YELLOW:
      counter_yellow++;
      goto label;
    case GREEN:
      counter_green++;
      goto label;
    default:
      printf("ERROR\n");
    }
  label:;
  }
  printf("pair of reds: %d and %d sock\n", counter_red / 2, counter_red % 2);
  printf("pair of yellows: %d and %d sock\n", counter_yellow / 2,
         counter_yellow % 2);
  printf("pair of greens: %d and %d sock\n", counter_green / 2,
         counter_green % 2);
  printf("total pairs of socks: %d",
         counter_red / 2 + counter_yellow / 2 + counter_green / 2);
}

int main() {
  BOX value;
  infoInput(&value);
  countSocks(&value);
  return 0;
}
