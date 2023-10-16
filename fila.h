typedef struct telemento elemento;
typedef elemento * fila;

//Recebe uma pilha e um caratere, empilha o caractere
// e devolve o endereco da nova pilha
elemento * empilhar(elemento * F, char c);

//comentario
fila desempilhar(fila F, char * resultado);

//comentario
int pilha_vazia(fila F);