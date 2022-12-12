#include <iostream>
using namespace std;
#define maximo 10


struct fila{
 int dado;
 fila  *prox;
};

struct pilha{
  int dado;
  pilha *prox;
};

void push(pilha * & topo){
  
 int dado = 1;

  while(dado != 0){
    cout << "\n\nDigite o valor:\n";
    cin >> dado;
    
   if(dado >= 1){
     
     if(topo == NULL){  
       
      pilha *novo = NULL;  
       novo = (pilha*) calloc (1, sizeof(pilha));  
       novo->dado = dado; 
       topo = novo;
       topo->prox = NULL;  
      
      cout << "\n  --- Valor " << dado << " Adicionado à pilha! ---\n\n"; 
    }  
       
     else{ 
      pilha *novo = NULL;
      novo = (pilha*) calloc (1, sizeof(pilha)); 
     
      novo->dado = dado;
      novo->prox = topo;
      topo = novo;
      cout << "\n  --- Valor " << dado << " Adicionado à pilha! ---\n\n"; 
      }
   }
   else{
      cout <<"Valor 0 acionado, pilha encerrada!\n";
    }
    } 
  }
  
int pop(pilha * & topo){ 
  
	pilha * aux = topo;              
  int val= aux->dado;                   

  if(aux->prox == NULL){
    free(aux);
    return val;
  }
    
  else{
	 topo = aux->prox;      
   free(aux);               
	 return val;
   }   
 }

void enqueue(fila * & primeiro, fila * & ultimo, int dado){

    if(ultimo == NULL){   
      
    fila *novo = NULL;  
     novo = (fila*) calloc (1, sizeof(fila)); 
      
     novo->dado = dado;   
     novo->prox = NULL;  
     primeiro = novo;   
     ultimo = novo;
     return;
      }
      
    else { 
    fila *novo = NULL; 
    novo = (fila*) calloc (1, sizeof(fila));
      
      novo->dado = dado;
      novo->prox = NULL;
      ultimo->prox = novo;
      ultimo = novo; 
   } 
  }
      
void pilhaPfila(pilha *& topo, fila *& primeiro_par, fila *& ultimo_par, fila *& primeiro_impar, fila *& ultimo_impar){
  
 pilha *aux = topo;
 
  while(aux->prox != NULL){
    cout <<"\n\nO topo atual é: "<<aux->dado;
    
     if(aux->dado %2 == 0){
     cout<<"  (PAR)\n\n";
     enqueue(primeiro_par, ultimo_par, pop(aux));
    }
       
    else{
   cout << "  (IMPAR)\n\n";
     enqueue(primeiro_impar, ultimo_impar, pop(aux));
    }
}
  if((aux->dado % 2) == 0 ){
    cout <<"\n\nO topo atual é: "<<aux->dado;
    cout<<"  (PAR)\n\n";
    enqueue(primeiro_par, ultimo_par, pop(aux));
  }

  else{
    cout <<"\n\nO topo atual é: "<<aux->dado;
    cout << "  (IMPAR)\n\n";
    enqueue(primeiro_impar, ultimo_impar, pop(aux));
  }

  
 fila *aux_par = primeiro_par;
 fila *aux_impar = primeiro_impar;

  if(aux_par == NULL){
    cout<<"\n\nNenhum elemento PAR encontrado!\n";
  }
  else{
  cout << "\n\nfila par:\n";
  while(aux_par != NULL){
    cout <<"\t" << aux_par->dado;
    aux_par = aux_par->prox;
  }
  }
  
  if(aux_impar == NULL){
    cout<<"\n\nNenhum elemento IMPAR encontrado!\n";
    }
  else{
  cout << "\n\nfila impar:\n";
  while(aux_impar != NULL){
    cout <<"\t"<< aux_impar->dado;
    aux_impar = aux_impar->prox;
    }
  }
}

int main() {

  pilha *topo = NULL;

  push(topo);

  fila * f1pri = NULL;
  fila * f1ult = NULL;
  fila * f2pri = NULL;
  fila * f2ult = NULL;

  pilhaPfila(topo, f1pri, f1ult, f2pri, f2ult);
  
}
