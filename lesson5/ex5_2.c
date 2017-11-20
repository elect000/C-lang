#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct trie {
  struct trie *child;
  struct trie *next;
  char c;
} trie_t;


void init_trie(trie_t *ptr); //
void add_to_trie(char *str, trie_t *ptr); //
trie_t *find_in_trie(char *str, trie_t *ptr);

void init_trie(trie_t *ptr) {
  ptr->c = '\0';
  ptr->next = NULL;
  ptr->child = NULL;
}

trie_t *new_trie(void)
{
  trie_t *ptr;

  if ((ptr = malloc(sizeof(trie_t))) == NULL) {
    fprintf(stderr, "Out of memory\n");
    exit(1);
  }
  init_trie(ptr);

  return ptr;
}

void add_to_trie(char *str, trie_t *ptr)
{
  if (strlen(str) == 0) {
    if (ptr->c == '\0') {
      ptr->c = '.';
      return;
    } else if (ptr->c == '.') {
      return;
    } else if (ptr->next == NULL) {
      ptr->next = new_trie();
      ptr->next->c = '.';
      return;
    } else {
      add_to_trie(str, ptr->next);
      return;
    }
  }

  if (ptr->c == '\0') {
    ptr->c = *str;
    ptr->child = new_trie();
    add_to_trie(++str, ptr->child);
  } else if (ptr->c == *str) {
    add_to_trie(++str, ptr->child);
  } else if (ptr->next == NULL) {
    ptr->next = new_trie();
    ptr->next->child = new_trie();
    ptr->next->c = *str;
    add_to_trie(++str, ptr->next->child);
  } else {
    add_to_trie(str, ptr->next);
  }
}

trie_t *find_in_trie(char *str, trie_t *ptr) {
  
  if(strlen(str) == 0) {
    if (ptr->c == '.') {
      return ptr;
    } else if (ptr->next == NULL) {
      return NULL;
    } else {
      find_in_trie(str, ptr->next);
    }
  } else if (ptr->c == *str) {
    find_in_trie(++str, ptr->child);
  } else if (ptr->next == NULL) {
    return NULL;
  } else {
    find_in_trie(str, ptr->next);
  }
}

int main(int argc, char *argv[])
{
  FILE *f;
  char str[512];
  trie_t root;

  if (argc != 3) {
    fprintf(stderr, "Missing argument\n");
    exit(1);
  }

  if ((f = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "Can't open %s\n", argv[1]);
    exit(1);
  }

  init_trie(&root);
  while (fgets(str, 512, f)) {
    if (str[strlen(str) - 1] == '\n') {
      str[strlen(str) - 1] = '\0';
    }
    add_to_trie(str, &root);
  }

  fclose(f);

  if (find_in_trie(argv[2], &root) != NULL) {
    printf("%s: \"%s\" is found in %s\n", argv[0], argv[2], argv[1]);
  } else {
    printf("%s: \"%s\" is not found in %s\n", argv[0], argv[2], argv[1]);
  }
  return 0;
}
