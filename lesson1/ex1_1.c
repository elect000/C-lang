#include <stdio.h>
#define N 100

int main(void)
{
  double a[N][N], b[N][N], tmp;
  int i, j, k, n;
  double c[N];
  double tmp2;

  /*  printf("Input matrix size\n"); */
  scanf("%d", &n);

  /* create matrix */
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      a[i][j] = 0.0;
      b[i][j] = 0.0;
    }
    c[i] = 0.0;
  }
  /* set value */
  for (i = 0; i < n; i++) {
    b[i][i] = 1.0;
  }

  /* read value */
  for(i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      /* if you wanna use %f in #scan, you should use %lf */
      scanf("%lf", &a[i][j]);
    }
    scanf("%lf", &c[i]);
  }

  /* calculate */
  for (k = 0; k < n ; k++) {
    tmp = a[k][k];
    for (i = 0; i < n; i++) {
      a[k][i] /= tmp;
      b[k][i] /= tmp;
    }
    for (i = 0; i < n ; i++) {
      if (i != k) {
        tmp = a[i][k];
        for (j = 0; j < n; j++) {
          a[i][j] -= a[k][j] * tmp;
          b[i][j] -= b[k][j] * tmp;
        }
      }
    }
  }

  /* b is calculated matrix */
  /* calculate & print */
  for (i = 0; i < n; i++) {
    tmp2 = 0.0;
    for (j = 0; j < n; j++) {
      tmp2 += c[j] * b[i][j];
    }
    printf("%f\n", tmp2);
  }
  return 0;
}
