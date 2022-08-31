#include <stdio.h>
#include <stdlib.h>

double **LeMatriz(char nome[20], int *m, int *n) {
  double **a;
  int i, j;
  FILE *arq;

  arq = fopen(nome, "r");
  fscanf(arq, "%d", m);
  fscanf(arq, "%d", n);

  a = (double **)malloc(*m * sizeof(double *));
  for (i = 0; i < *m; i++)
    a[i] = (double *)malloc(*n * sizeof(double));

  for (i = 0; i < *m; i++) {
    for (j = 0; j < *n; j++) {
      fscanf(arq, "%lf", &a[i][j]);
      // printf("%d", a[i][j]);
    }
    puts("");
  }
  // for(i=0; i<n;i++) printf("%d", a[i]);
  return a;
}

double **EliminaGauss(double **M, int *m, int *n) {

  double l;
  int i, k, j;

  for (k = 0; k < *n - 1; k++) {
    for (i = k + 1; i < *m - 1; i++) {

      l = M[i][k] / M[k][k];
      for (j = 0; j < *n; j++) {
        M[i][j] = l * M[k][j] - M[i][j];
      }
    }
  }

  return M;
}

int main() {
  double **M;
  int i, n, m, j;
  FILE *arq;

  M = LeMatriz("matriz3x3.dat", &m, &n);
  M = EliminaGauss(M, &m, &n);

  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      // fscanf(arq, "%d",&a[i][j]);
      printf("%.2lf ", M[i][j]);
    }
    puts("");
  }
  // for(i=0; i<n;i++) printf("%d", a[i]);
}
