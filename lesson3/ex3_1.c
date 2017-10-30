#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct record {
  int no;
  char name[512];
  int point;
  struct record *next;
};

struct record *head = NULL;

void insert_list(int no, char *name, int x)
{
  struct record *p, *q, *t;

  t = (struct record *)malloc(sizeof(struct record));
  if (t == NULL) {
    fprintf(stderr, "Out of memory\n");
    exit(1);
  }
  t->no = no;
  strcpy(t->name, name);
  t->point = x;

  q = NULL;
  for (p = head; p != NULL; p = p->next) {
    if (strcmp(p->name, name) >= 0) {
      break;
    }
    q = p;
  }

  if (q != NULL) {
    q->next = t;
  } else {
    head = t;
  }
  t-> next = p;
}

int main(int argc, char *argv[])
{
  FILE *fp;
  int nlines, i;
  int no, x;
  char name[512], buf[1024];
  struct record *p;

  if (argc != 2) {
    fprintf(stderr, "Missing file argument\n");
    return 1;
  }

  if ((fp = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "Can't open %s\n", argv[1]);
    return 1;
  }

  if (fgets(buf, sizeof(buf), fp) == NULL) {
    fprintf(stderr, "Can't read input data\n");
    return 1;
  }
  if (sscanf(buf, "%d", &nlines) != 1) {
    fprintf(stderr, "Invalid input data\n");
    return 1;
  }

  for (i = 0; i < nlines; i++) {
    if (fgets(buf, sizeof(buf), fp) == NULL) {
      fprintf(stderr, "Can't read input data\n");
      return 1;
    }
    if (sscanf(buf, "%d %s %d", &no, name, &x) != 3) {
      fprintf(stderr, "Invalid input data\n");
      return 1;
    }
    insert_list(no, name, x);
  }

  fclose(fp);

  for (p = head; p != NULL; p = p->next) {
    printf("%d %s %d\n", p->no, p->name, p->point);
  }

  return 0;
}
