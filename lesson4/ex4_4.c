#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *insert_data(int x, struct node *p)
{
  struct node *nd;
  if (p == NULL) {
    if ((nd = (struct node *)malloc(sizeof(struct node))) == NULL) {
      fprintf(stderr, "Out of memory\n");
      exit(1);
    }
    nd->data = x;
    nd->left = NULL;
    nd->right = NULL;

    return nd;
  }

  if (x == p->data) {
    return p;
  }

  if (x < p->data) {
    p->left = insert_data(x, p->left);
  } else {
    p->right = insert_data(x, p->right);
  }

  return p;
}

void print_tree(struct node *p)
{
  if (p == NULL) {
    return;
  }

  print_tree(p->left);
  printf("%d\n", p->data);
  print_tree(p->right);
}

int print_sum(struct node *p)
{
  if (p == NULL) {
    return 0;
  }
  return (p->data + (print_sum (p->left) + (print_sum (p->right))));
}

int search_tree(int x, struct node *p);
int search_tree(int x, struct node *p) {
  if (p == NULL) {
    return 0;
  } else
    if (p->data == x) {
      return 1;
    } else {
      if((search_tree(x, p->left)) + (search_tree(x, p->right)) > 0) {
        return 1;
      } else {
        return 0;
      }
    }
}

int main(int argc, char *argv[])
{
  FILE *fp;
  int i, x;
  struct node *root = NULL;

  if (argc != 2) {
    fprintf(stderr, "Missing file argument\n");
    exit(1);
  }

  if ((fp = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "Can't open %s\n", argv[1]);
    exit(1);
  }

  for (i = 0; i < 100; i++) {
    if (fscanf(fp, "%d", &x) != 1) {
      fprintf(stderr, "Can't read data\n");
      exit(1);
    }
    if (x <= 0) {
      fprintf(stderr, "Invalid data: %d\n", x);
      exit(1);
    }
    root = insert_data(x, root);
  }

  fclose(fp);

  print_tree(root);
  printf("Sum: %d \n", print_sum(root));
  while (1) {
    printf("Input number ");
    if (scanf("%d", &x) == EOF) {
      fprintf(stderr, "Can't read input\n");
      exit(1);
    }
    if (x <= 0) {
      break;
    }
    if (search_tree(x, root) == 1) {
      printf("%d: Found\n", x);
    } else {
      printf("%d: Not found\n", x);
    }
  }

  return 0;
}
