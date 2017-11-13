#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct record {
  char word[65];
  int count;
  struct record *next;
};

int read_word(FILE *fp, char *word);
void add_word(char *word);

struct record *head = NULL;

int read_word(FILE *fp, char *word) {
  int count = 0;
  char c;
  int end = 0;
  while ((c = fgetc(fp)) != EOF) {
    if (c == '-'
        || (c >= 'A' && c <= 'Z')
        || (c >= 'a' && c <= 'z')
        || (c >= '0' && c <= '9')) {
      word[count] = c;
      count++;
      end = 1;
    } else if (end) {
      word[count++] = '\0';
      break;
    }
  }
  if (c == EOF) {
    return 0;
  } else {
    return 1;
  }
}

void add_word (char *word) {
  int flag = 0;
  struct record *p, *q, *t;
  t = (struct record *)malloc(sizeof(struct record));
  if (t == NULL) {
    fprintf(stderr, "Out of memory\n");
    exit(1);
  }
  strcpy(t->word, word);
  t->count = 1;
  q = NULL;
  for (p = head; p != NULL; p = p->next) {
    if (strcmp(p->word, word) > 0) {
      break;
    } else if (strcmp(p->word, word) == 0) {
      flag = 1;
      break;
    }
    q = p;
  }

  if (q != NULL) {
    q->next = t;
  } else {
    head = t;
  }
  if (flag) {
    t->count = p->count + 1;
    t->next = p->next;
  } else {
    t->next = p;
  }
}

int main(int argc, char *argv[])
{
  FILE *fp;
  char word[65];
  struct record *p;

  if (argc != 2) {
    fprintf(stderr, "Missing file argument\n");
    return 1;
  }

  if ((fp = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "Can't open %s\n", argv[1]);
    return 1;
  }

  while (read_word(fp, word)) {
    add_word(word);
  }

  fclose(fp);

  for (p = head; p != NULL; p = p->next) {
    printf("%s %d\n", p->word, p->count);
  }
  return 0;
}
