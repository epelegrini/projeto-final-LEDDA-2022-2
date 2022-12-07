#include <iostream>
#define maximo 8

using namespace std;

struct Stack { 
    int dado;
    Stack *prox; 
}; 

int quantidade(Stack * & topo){ 
  
 Stack *temp = topo; 
 int qnt = 0; 
  
   while(temp != NULL){  
     qnt++; 
     temp=temp->prox; 
  } 
   return qnt; 
}

void push(Stack * & topo, int dado){

  if(maximo <= 0){  
    printf("Pilha sem espaços disponiveis!\n");
   } 
    
  else {    
    if(topo == NULL){ 
      
      Stack *pilha = NULL;  
      pilha = (Stack*) calloc (1, sizeof(Stack));  
      
      if(pilha == NULL){  
     printf("ERRO DE ALOCAÇÂO!\n");
      } 
        
      else{ 
      pilha->dado = dado; 
      pilha->prox = NULL;
      topo = pilha; 
      cout << "\n\nValor " << dado << " Adicionado à pilha!\n";  
      return;
      }
   }
      
  else if(quantidade(topo) < maximo) { 
    Stack *pilha = NULL;
      pilha = (Stack*) calloc (1, sizeof(Stack)); 
    
    if(pilha == NULL){ 
      printf("ERRO DE ALOCAÇÂO!\n");}
    else{ 
      pilha->dado = dado;
      pilha->prox = topo;
      topo = pilha;
      cout << "\nValor " << dado << " Adicionado à pilha!\n";   
     } 
    } 
   }  
  }

int pop(struct Stack * & topo){  
  
	Stack * aux;              
    aux = topo;
  
  int val;                   
    val = aux->dado;
  
	 topo = aux->prox;        
   free(aux);               

  if(aux != topo){           
    cout << "\n"<< val << " Removido da pilha! \n";
  }

  else{
    cout << "Erro ao remover nivel atual!\n";
  }
	 return val;             
 }

void listar(Stack * & topo){
  if(topo == NULL){  
		printf("\nPilha vazia\n");
	}

  else{ 
    
		printf("\nPilha Atual:\n");
		struct Stack * aux = topo;
		while(aux != NULL){ 
			printf("%d\n", aux->dado);
			aux = aux->prox;  
			}
	}
}

void Isfull_Isempty(Stack *& topo) { 
  
  if(topo == NULL){ 
    cout << "\nPilha Vazia!\n";
  }
  else if(quantidade(topo) == maximo){
    cout << "\n\nPilha cheia!\n\n";
  }

  else{  
    cout << "\nPilha com " << maximo - quantidade(topo) << " espaços disponiveis\n";
    }
}

void consultar(Stack * topo, int c){ 
  Stack * aux;
  aux = topo;
  int nivel = 0;
 
 if(topo == NULL){
    cout << "Pilha Vazia!\n";
    return;
  }
  else{
    while(aux != NULL){
    if (aux->dado == c){ 
      printf("Valor encontrado no nivel %d\n", nivel);
      return;
    }
    else {  
      aux = aux->prox; 
      nivel++;
    } 
  }
   printf("Valor não encontrado na pilha!\n");
 }
}

int main() {
  
  Stack *topo = NULL; 
  int qtd; 

  Isfull_Isempty(topo); 

  for (int i=1;i<6;i++){ 
   push(topo, i*5);
  }
  
  Isfull_Isempty(topo);
  
  listar(topo);  
  qtd = quantidade(topo);  
  cout << "\nQuantidade de niveis na pilha: " << qtd << "\n";  
  
  pop(topo); 
  pop(topo);
  
  push(topo, 100);
    
  listar(topo);
  
  qtd = quantidade(topo);
  cout << "\nQuantidade de niveis na pilha: " << qtd << "\n\n";  

  consultar(topo, 5); 
}
