#include <stdio.h>

int string_length(char *string) {
  int i;
  for (i = 0; string[i] != '\0'; i++) {
  }
  return i;
}

void searchString(char *str, char *subStr) {
  int lengStr = string_length(str);
  int lengSubStr = string_length(subStr);
  int flag = 1, count = 0, i = 0, j = 0;
  // printf("do dai cua lengSubStr: %d\n", lengSubStr);

  for (i = 0; i < lengStr; i++) {
    // Find 1st letter of subStr in str
    if (*subStr == str[i]) {
      for (j = 0; j < lengSubStr; j++) {
        if (subStr[j] != str[i + j]) {
          flag = 0;
          goto label;
        }
      }
      if (flag == 1) {
        printf("Chuoi '%s' nam o vi tri %d\n", subStr, i);
      }
      count++;
    }
  label:;
  }
  printf("Chuoi '%s' xuat hien %d lan\n", subStr, count);
}

int main() {
  char str[] = {"day la mot chuoi string dai oi la dai"};
  char subStr[] = {"abc"};
  searchString(str, subStr);
}