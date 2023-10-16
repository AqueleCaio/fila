#include <stdio.h>
#include <stdlib.h>

typedef struct tfila {
  int dados[100];
  int p, u;
} fila;

fila *criarfila() {
  fila *F = (fila *)malloc(sizeof(fila));
  F->u = 0;
  F->p = 0;
  return F;
}

void colocarnafila(fila *F, int x) {
  F->dados[F->u] = x;
  F->u = F->u + 1;
  if (F->u == 100)
    F->u = 0;
  return;
}

int retirardafila(fila *F) {
  int primeiro = F->dados[F->p];
  F->dados[F->p] = -1;
  F->p++;
  if (F->p == 100)
    F->p = 0;
  return primeiro;
}

int filavazia(fila *F) {
  if (F->p == F->u)
    return 1;
  else
    return 0;
}

int filacheia(fila *F) {
  if (F->p == F->u + 1 || (F->p == 0 && F->u == 99))
    return 1;
  else
    return 0;
}

void distancias(int n, char **M) {
  int **dist = (int **)malloc(n * (sizeof(int *)));

  for (int i = 0; i < n; i++) {
    dist[i] = (int *)malloc(n * (sizeof(int)));
  }

  // Nao conheco caminho para nenhuma posição
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      dist[i][j] = n;
    }
  }

  fila *F = criarfila();
  colocarnafila(F, 0);

  // executa ate que todos os elementos da fila sejam retirados
  while (!filavazia(F)) {
    int i = retirardafila(F); // tira o primeiro elemento da fila

    for (int j = 0; j < n; j++) {

      if (M[i][j] == '0' && dist[i][j] == n)  // atribui as determinadas distancias de cada posiçao
      {

        dist[i][j] = i + j; //  em relacao ao primeiro elemento

      }
      
      else if (M[i][j] != '0' && dist[i][j] == n) 
      {

        dist[i][j] = n * n;

      }
    }
    if (i + 1 < n)
      colocarnafila(F, (i + 1));
  }

  // libera a memoria alocada na fila
  free(F);

  // imprime os valores referente as distancias da matriz
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", dist[i][j]);
    }
    printf("\n");
  }
}
