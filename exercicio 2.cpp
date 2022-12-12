#include <iostream>
#define maximo 10
using namespace std;

struct Queue { 
    int dado; 
    Queue * prox; 
}; 

int quantidade(Queue * & ultimo){ 
  
 Queue *temp = ultimo; 
 int qnt = 0;  
  
   while(temp != NULL){  
     qnt++; 
     temp=temp->prox; 
  } 
   return qnt; 
  }

void listar(Queue * & ultimo){
  if(ultimo == NULL){  
		printf("\n                     **Fila Atual vazia!**\n");
	}

  else{ 
    
		printf("\nFila Atual:\n");
		Queue * aux = ultimo;
    cout << "Ultimo  -->\t";
		while(aux != NULL){ 
			printf("\t%d\t", aux->dado);
			aux = aux->prox;  
			}
    cout << "\t<--  Primeiro\n\n\n";
	}
}
  
void Enqueue(Queue * & ultimo, Queue * & primeiro, int dado){

  if(maximo <= 0){   
    printf("Fila sem espaços disponiveis!\n");
   } 
    
  else {    
    if(ultimo == NULL){       
    
      Queue *fila = NULL;  
    fila = (Queue*) calloc (1, sizeof(Queue));  
      
      if(fila == NULL){     
     printf("ERRO DE ALOCAÇÂO!\n");
      } 
        
      else{  
      fila->dado = dado;   
      fila->prox = NULL;   
      primeiro = fila;    
      ultimo = fila;
      
      
      cout << "\n\n" << dado << " - Adicionado à fila!\n";  
        listar(ultimo);
      return;
      }
   }
      
  else if(quantidade(ultimo) < maximo) { 
   Queue *fila = NULL; 
    fila = (Queue*) calloc (1, sizeof(Queue)); 
    
    if(fila == NULL){ 
      printf("ERRO DE ALOCAÇÂO!\n");}
    else{ 
      fila->dado = dado;
      fila->prox = ultimo;
      ultimo = fila;
      cout << "\n" << dado << " - Adicionado à fila!\n";   
      listar(ultimo);
   } 
   } 
   }     
   }

int Dequeue(Queue * & primeiro, Queue * & ultimo){
  
if(ultimo != NULL){
	Queue * aux = ultimo;
  Queue *eliminar = primeiro;               
  
  int val;                   
    val = eliminar->dado;
  
  int d;
    d = (quantidade(ultimo) - 2);
  
  if(quantidade(ultimo) > 1){
  for (int i = 0; i< d; i++){
    aux=aux->prox; 
  }
     
  primeiro = aux; 
  free(eliminar); 

  primeiro->prox = NULL;
  if(eliminar != primeiro){           
    cout << "\n"<< val << " - Removido da fila!\n";
  }

  else{
    cout << "Erro ao remover nivel atual!\n";
  }
   listar(ultimo);
	 return val;             
 }
  
else{

  
    free(ultimo);
    ultimo = NULL;
  
  cout <<"\n" << val << " - Removido da fila!\n";
  cout <<"\n                   **A Lista foi esvaziada!** \n";
  listar(ultimo);
  return val;
  }
  }
  

else{
  return 0;
}
}
  
void Isfull_Isempty(Queue *& ultimo) { 
  if(ultimo == NULL){ 
    cout << "\nFila Vazia!\n";
  }
  else if(quantidade(ultimo) == maximo){
    cout << "\n\nFila cheia!\n\n";
  }

  else{  
    cout << "\nFila com " << maximo - quantidade(ultimo) << " espaços disponiveis\n";
    }
}

void consultar(Queue * ultimo, int c){
  Queue * aux;
  aux = ultimo;
  int nivel = quantidade(ultimo);
 
 if(ultimo == NULL){
    cout << "Pilha Vazia!\n";
    return;
  }
  else{
    while(aux != NULL){
    if (aux->dado == c){ 
     printf("\n\nValor encontrado na %dª posição!\n", nivel);
      return;
    }
    else {  
      aux = aux->prox; 
      nivel--;
    } 
  }
   printf("Valor não encontrado na pilha!\n");
 }
}

int main() {
  
  Queue *primeiro = NULL;;
  Queue *ultimo = NULL;;
  int i;
  int qtd; 

  Isfull_Isempty(ultimo);

  for (i=1;i<10;i++){
   Enqueue(ultimo, primeiro, i);
  }

  
  Isfull_Isempty(ultimo);

  Dequeue (primeiro, ultimo);
  Dequeue (primeiro, ultimo);
  Dequeue (primeiro, ultimo);
  Dequeue (primeiro, ultimo);
  
  consultar(ultimo, 6);
}
