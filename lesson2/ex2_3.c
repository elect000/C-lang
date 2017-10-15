#include <stdio.h>

struct _status {
  char name[256];
  int point;
};

int main(int argc, char *argv[])
{
  struct _status list[100];
  int num, i, j;
  FILE *fp;
  /* check argc */
  if (argc != 2) {
    fprintf(stderr, "Missing file argument\n");
    return 1;
  }
  /* open file */
  if ((fp = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "Cannot open %s\n", argv[1]);
    return 1;
  }
  fscanf(fp, "%d", &num);
  for (i = 0; i < num; ++i) {
    fscanf(fp, "%s %d", list[i].name, &(list[i].point));
  }
  /* print ORDER BY ASC */
  for (i = 0; i < 100; ++i) {
    for (j = 0; j < num; ++j) {
      if (list[j].point == i) {
        printf("%s %d\n", list[j].name, list[j].point);
      }
    }
  }

  return 0;
}
