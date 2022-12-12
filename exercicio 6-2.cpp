#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct cliente{
int tran;
cliente * prox;
cliente *ant;
int ini;
int fim;
int tempmed;
};

struct caixa{
bool livre = true;
int ini;
int fim;
};

void my_init() {
    srand(time(NULL));
}

int get_random(int x) {
    return rand() % x;
}

void aloc(cliente *& inicio, cliente *& fim){
  
  time_t segundos;
  time(&segundos);
  int tipo = get_random(8);
  
  int tempo = segundos + get_random(15);

  cliente *novo = (cliente *)calloc(1, sizeof(cliente));
  novo->tran = tipo;
  novo->prox = NULL;
  novo->tempmed = 0;
  
  if (inicio == NULL) {
    inicio = novo;
    fim = novo;
    novo->ini = tempo;
    
  } else {
    novo->ini = fim->ini + get_random(15);
    fim->prox = novo;
    fim = novo;
  }
}

int dalloc(cliente *&inicio, int &tempomedio) {
  tempomedio = tempomedio + inicio->tempmed;
  
  if (inicio == NULL) {
    printf("\nFila vazia!");
  } else {
    cliente *aux = inicio;
    inicio = inicio->prox;
    free(aux);
  }
  return tempomedio;
}

void check(caixa *&caixa){
  time_t segundos;
  time(&segundos);
  
  if(caixa->fim > segundos){
    caixa->livre = true;
  }

  else{
    caixa->livre = true;
  }
}

int main() {  
  
  my_init();
  
time_t segundos;
time(&segundos);

int fila = 0;
  
  int tempomedtotalcx1 = 0;
  int tempomedtotalcx2 = 0;
  int tempomedtotalcx3 = 0;
  
 cliente *aux;
  
  caixa *caixa1 = (caixa*) calloc (1,sizeof(caixa));
  caixa1->fim = 0;
  caixa1->livre = true;
  caixa *caixa2 = (caixa*) calloc (1,sizeof(caixa));
  caixa2->fim = 0;
  caixa2->livre = true;
  caixa *caixa3 = (caixa*) calloc (1,sizeof(caixa));
  caixa3->fim = 0;
  caixa3->livre = true;
  
  cliente *inicio = NULL;
  cliente *fim = NULL;
  
  srand(std::time(nullptr));
   fila = std::rand() % 100;
  
  if(fila == 0){
    fila = 1;
  }

  for(int i = 0; i< fila; i++){
    
    aloc(inicio, fim);

  }

  cout << "Pessoas na fila: " << fila << "\n\n\n";
  
  while (inicio != NULL ) { 

    
   if(inicio != NULL){ 
  if(caixa1->livre == true){

    check(caixa2);
    check(caixa3);
    caixa1->livre = false;
    
    int tempo = segundos;
    
        if(inicio->tran == 0){caixa1->fim = (inicio->ini + 10);}  
        if(inicio->tran == 1){caixa1->fim = (inicio->ini + 20);}  
        if(inicio->tran == 2){caixa1->fim = (inicio->ini + 30);}  
        if(inicio->tran == 3){caixa1->fim = (inicio->ini + 40);}  
        if(inicio->tran == 4){caixa1->fim = (inicio->ini + 50);}  
        if(inicio->tran == 5){caixa1->fim = (inicio->ini + 60);}  
        if(inicio->tran == 6){caixa1->fim = (inicio->ini + 70);}  
        if(inicio->tran == 7){caixa1->fim = (inicio->ini + 80);}    
  
    inicio->tempmed = (caixa1->fim - inicio->ini);
    printf("Caixa: 1 | tipo transação: = %d | Tempo de espera: %d\n\n", inicio->tran, inicio->tempmed);
    tempomedtotalcx1 = dalloc(inicio, tempomedtotalcx1);
    
  }
 }
    
    if(inicio != NULL){ 
    if(caixa2->livre == true){

    check(caixa1);
    check(caixa3);
    caixa2->ini = segundos;
    caixa2->livre = false;
  
    
    int tempo = segundos;
    
        if(inicio->tran == 0){caixa2->fim = (inicio->ini + 10);}  
        if(inicio->tran == 1){caixa2->fim = (inicio->ini + 20);}  
        if(inicio->tran == 2){caixa2->fim = (inicio->ini + 30);}  
        if(inicio->tran == 3){caixa2->fim = (inicio->ini + 40);}  
        if(inicio->tran == 4){caixa2->fim = (inicio->ini + 50);}  
        if(inicio->tran == 5){caixa2->fim = (inicio->ini + 60);}  
        if(inicio->tran == 6){caixa2->fim = (inicio->ini + 70);}  
        if(inicio->tran == 7){caixa2->fim = (inicio->ini + 80);}    
  
    inicio->tempmed = (caixa2->fim - inicio->ini);
      
      printf("Caixa: 2 | tipo transação: = %d | Tempo de espera: %d\n\n", inicio->tran, inicio->tempmed);
      
    tempomedtotalcx2 = dalloc(inicio, tempomedtotalcx2);
    
   }
  }
    if(inicio != NULL){ 
    if(caixa3->livre == true){
    check(caixa1);
    check(caixa2);
    caixa3->ini = segundos;
    caixa3->livre = false;
    
    int tempo = segundos;
    
        if(inicio->tran == 0){caixa3->fim = (inicio->ini + 10);}  
        if(inicio->tran == 1){caixa3->fim = (inicio->ini + 20);}  
        if(inicio->tran == 2){caixa3->fim = (inicio->ini + 30);}  
        if(inicio->tran == 3){caixa3->fim = (inicio->ini + 40);}  
        if(inicio->tran == 4){caixa3->fim = (inicio->ini + 50);}  
        if(inicio->tran == 5){caixa3->fim = (inicio->ini + 60);}  
        if(inicio->tran == 6){caixa3->fim = (inicio->ini + 70);}  
        if(inicio->tran == 7){caixa3->fim = (inicio->ini + 80);}    
  
    inicio->tempmed = (caixa3->fim - inicio->ini);
      
     printf("Caixa: 3 | tipo transação: = %d | Tempo de espera: %d\n\n", inicio->tran, inicio->tempmed);
    tempomedtotalcx3 = dalloc(inicio, tempomedtotalcx3);    
     }
    }
   }
  
  printf("\n\nTempo medio clientes caixa 1 %d\n", tempomedtotalcx1);
  printf("Tempo medio clientes caixa 2 %d\n", tempomedtotalcx2);
  printf("Tempo medio clientes caixa 3 %d\n", tempomedtotalcx3);
  
  }
