#include <stdio.h>

int main(int argc, char *argv[])
{
  int ch, count;
  FILE *fp;

  /* check argc */
  if (argc != 2) {
    fprintf(stderr, "Missing file argument\n");
    return 1;
  }

  if ((fp = fopen(argv[1],"r")) == NULL) {
    /* open the file */
    fprintf(stderr, "Cannot open %s\n", argv[1]);
  }

  count = 0;
  while((ch = fgetc(fp)) != EOF) {
    count++;
  }

  printf("%d elements\n", count);
  fclose(fp);
  return 0;
}
