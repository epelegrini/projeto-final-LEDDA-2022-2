#include <iostream>

using namespace std;
int i = 0;
struct fila{
 int dado;
 fila *prox;
};

void enqueue(fila *& primeiro, fila *& ultimo, int dado){

  fila *novo = NULL;

  if(primeiro == NULL){
   novo = (fila*) calloc (1, sizeof(fila));

   if(novo == NULL){
     cout << "Erro ao alocar memória!";
     return;
   } 
   else{
     novo->dado = dado;
     primeiro = novo;
     ultimo = novo;
     novo->prox = NULL;
     i++;
     cout<< i << "º Nó adicionado com sucesso!\n";
   } 
  }

  else{
    novo = (fila*) calloc (1, sizeof(fila));

   if(novo == NULL){
     cout << "Erro ao alocar memória!";
     return;
   } 
   else{
     novo->dado = dado;
     novo->prox = NULL;
     ultimo->prox = novo;
     ultimo = novo;
     i++;
     cout<< i << "º Nó adicionado com sucesso!\n";
  }

    
    
}}

void organizar(fila * primeiro1, fila * ultimo1, fila * primeiro2, fila * ultimo2, fila * primeiro3, fila * ultimo3){
  
cout << "\n\n     *** FILA 3 ***\n";
while(primeiro1 != NULL && primeiro2 != NULL){
  if(primeiro1->dado < primeiro2->dado){
    enqueue(primeiro3, ultimo3, primeiro1->dado);
    primeiro1 = primeiro1->prox;
  }
  else{
    enqueue(primeiro3, ultimo3, primeiro2->dado);
    primeiro2 = primeiro2->prox;
  }
}

while(primeiro1 != NULL || primeiro2 != NULL){
  if(primeiro1 == NULL){
    enqueue(primeiro3, ultimo3, primeiro2->dado);
    primeiro2 = primeiro2->prox;
  }

  else{
    enqueue(primeiro3, ultimo3, primeiro1->dado);
    primeiro1 = primeiro1->prox;
  }
}
  


  fila *aux = primeiro3;
  cout << "\n\n\n             *** FILA 3 ***\n\n";
  cout << "Primeiro -> ";
  while(aux != NULL){
  cout <<"\t" << aux->dado;
  aux = aux->prox;
  }
  cout << "\t <- Ultimo";
}

int main(){
int d;
  
  fila *primeiro1 = NULL, *primeiro2 = NULL, *primeiro3 = NULL, *ultimo1 = NULL, *ultimo2 = NULL, *ultimo3 = NULL;

  cout << "\n\n     *** FILA 1 ***\n";
  
  enqueue(primeiro1, ultimo1, 5);
  enqueue(primeiro1, ultimo1, 7);
  enqueue(primeiro1, ultimo1, 9);
  enqueue(primeiro1, ultimo1, 11);

  cout << "\n\n     *** FILA 2 ***\n";
  i = 0;
  enqueue(primeiro2, ultimo2, 4);
  enqueue(primeiro2, ultimo2, 6);
  enqueue(primeiro2, ultimo2, 8);
  enqueue(primeiro2, ultimo2, 10);
  
  i = 0;
  organizar(primeiro1, ultimo1, primeiro2, ultimo2, primeiro3, ultimo3);
}
