#include <stdio.h>
#include <stdlib.h>
#include "fila.c"
#include "fila.h"

void distancias(int n, char ** M){
  int ** dist = (int**) malloc(n* (sizeof(int*)));
  
  for(int i=0; i<n; i++){
   dist[i] = (int*) malloc(n*(sizeof(int)));
  }


  //Nao conheco caminho para nenhuma posição
  for(int i = 0; i < n; i++){
    for(int j = 0; j< n; j++){ 
    dist[i][j] = n*n;
    }
  }
  

  fila * F = criarfila();


  int coluna = 0, linha = 0;
  int pre_coluna, pre_linha;
  dist[coluna][linha] = 0;
  colocarnafila(F,coluna);
  colocarnafila(F,linha);


  // calcula a distancia das posições até que a fila esteja vazia
  while(!filavazia(F))
  {
    dist[coluna][linha];
    M[coluna][linha];
  
    // move para a direita e atribui um valor a posiçao caso nao seja uma 'parede'
    if(coluna+1 < n && M[coluna+1][linha] != 'X' && dist[coluna+1][linha] == n*n){ 
      
      // atribui um valor de distancia para a prox posição
      dist[coluna+1][linha] = dist[coluna][linha] + 1;
      
      // guarda o caminho percorrido
      colocarnafila(F, coluna);
      colocarnafila(F, linha);
      coluna = coluna + 1;
      dist[coluna][linha];

      
    }
    
    // move para a esquerda e atribui um valor a posiçao caso nao seja uma 'parede'
    else if(coluna - 1 >=0 && M[coluna-1][linha] != 'X' && dist[coluna-1][linha] == n*n){ 
      
      // atribui um valor de distancia para a prox posição
      dist[coluna-1][linha] = dist[coluna][linha] - 1;
      
      // guarda o caminho percorrido
      colocarnafila(F, coluna);
      colocarnafila(F, linha);
      coluna = coluna - 1;
      dist[coluna][linha];
   
      
    }

    // move para baixo e atribui um valor a posiçao caso nao seja uma 'parede'
    else if(linha + 1 < n && M[coluna][linha+1] != 'X' && dist[coluna][linha+1] == n*n){ //baixo
      
      // atribui um valor de distancia para a prox posição
      dist[coluna][linha+1] = dist[coluna][linha] + 1;
      
      // guarda o caminho percorrido
      colocarnafila(F, coluna);
      colocarnafila(F, linha);
      linha = linha + 1;
      dist[coluna][linha];

      
    }

    // move para cima e atribui um valor a posiçao caso nao seja uma 'parede'
    else if(linha - 1 >= 0 && M[coluna][linha-1] != 'X'&& dist[coluna][linha-1] == n*n){ //cima
      
      // checa se possui um caminho para a proxima posiçao se mover
      if(M[coluna-1][linha-1] != 'X' && dist[coluna-1][linha-1] != n*n){ 
        
        // atribui um valor de distancia para a prox posição
        dist[coluna][linha-1] = dist[coluna][linha] - 1;
  
        // guarda o caminho percorrido
        colocarnafila(F, coluna);
        colocarnafila(F, linha);
        linha = linha - 1;
        dist[coluna][linha];
      }

      // caso nao houver caminhos para a movimentaçao, a posição recebera +1
      else{
        
        // atribui um valor de distancia para a prox posição
        dist[coluna][linha-1] = dist[coluna][linha] + 1;
        
        // guarda o caminho percorrido
        colocarnafila(F, coluna);
        colocarnafila(F, linha);
        linha = linha - 1;
        dist[coluna][linha];
      }

 
    ;
    }
    // retorna o caminho salvo na fila caso nao houver posiçoes disponiveis para receberem valores ao redor
    else{
      coluna = retirardafila(F);
      linha = retirardafila(F);
      dist[coluna][linha];


    }
  }

     for(int i=0; i < n; i++){
      for(int j= 0; j < n; j++){
        printf("%d ", dist[j][i]);
    }
    printf("\n");
  }
}

//*********************************************************
//*********************************************************


int main(int argc, char* argv[]){
  
  int n;
  char ** mapa;

  //Recebe um numero n
  scanf("%d", &n);
  //Alocação dinâmica da matriz
  mapa =  (char**) malloc(n* (sizeof(char*)));

  for(int i=0; i<n; i++){
    mapa[i] = (char*) malloc(n*(sizeof(char)));
  }
  
  // recebe valores para a matriz
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
        scanf("%c", &(mapa[i][j]));
    }
  }

  // imprime as distancias da matriz
  distancias(n, mapa);


  return 0;
}