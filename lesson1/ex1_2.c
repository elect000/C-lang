#include <stdio.h>
#include <string.h>

int main(void)
{
  char str1[100], str2[100];
  int i, j, n;

  str1[sizeof(str1) - 1] = '\0';
  str2[sizeof(str2) - 1] = '\0';

  /* read strings */
  printf("Input string(1) ");
  scanf("%s", str1);
  printf("Input string(2) ");
  scanf("%s", str2);

  /* string(1) length */
  i = 0;
  n = 0;
  while (str1[i] != '\0') {
    ++n;
    ++i;
  }

  /* check strings */
  for (j = 0; j < n; ++j) {
    i = 0;
    while (str2[i] != '\0') {
      if (str2[i] == str1[j]) {
        printf("%c", str2[i]);
      }
      ++i;
    }
  }
  printf("\n");
  return 0;
}
