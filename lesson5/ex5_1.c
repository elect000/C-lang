#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct trie {
  struct trie *array[256];
} trie_t;

void init_trie(trie_t *ptr)
{
  int i;
  for (i = 0; i < 256; ++i) {
    ptr->array[i] = NULL;
  }
  return;
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
    ptr->array['.'] = new_trie();
    return;
  } 

  if (ptr->array[*str] == NULL) {
    ptr->array[*str] = new_trie();
  } 

  add_to_trie(str + 1, ptr->array[*str]);
}

trie_t *find_in_trie(char *str, trie_t *ptr)
{
  if (str[0] == '\0') {
    if (ptr->array ['.'] == NULL) return NULL;
    else return ptr;
  } else if (ptr->array[str[0]] == NULL) {
    return NULL;
  } else {
    find_in_trie (++str, ptr->array[*str]);
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
