#include <stdio.h>

int main(int argc, char *argv[])
{
  int ch;
  FILE *sfp, *dfp;
  /* check argc */
  if (argc != 3) {
    fprintf(stderr, "Missing file argument\n");
    return 1;
  }
  /* open file to read */
  if ((sfp = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "Cannot open %s\n", argv[1]);
    return 1;
  }
  /* open file to write */
  if ((dfp = fopen(argv[2], "w")) == NULL) {
    fprintf(stderr, "Cannot open %s\n", argv[2]);
    fclose(sfp);
    return 1;
  }
  while ((ch = fgetc(sfp)) != EOF) {
    /* big element? */
    if (ch >= 'a' && ch <= 'z') {
      fputc((ch - 'a' + 'A'), dfp);
    }
    else {
    fputc(ch, dfp);
    }
  }
  /* close files */
  fclose(dfp);
  fclose(sfp);

  return 0;
}
