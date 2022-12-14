#include <iostream>
using namespace std;

struct vinho{
char nome[30], pais[30], tipo[30];
int safra;
vinho *next, *prev;
};

int menu(){
  system("clear||cls");
  int select;
  
  cout << "          ***********   Vinícola dos muleke  ***********       v4.7\n\n";
  
  cout << "Digite 1 para adicionar vinhos à adega;\n\nDigite 2 para remover vinhos da adega\n\nDigite 3 para listar as primeiras e ultimas adições\n\nDigite 4 para encerrar o programa\n";
  cin>>select;
  return select;
}

void aloc(vinho *& first, vinho *& last){
system("clear||cls");
  vinho *novo;
  novo = (vinho*) calloc (1, sizeof(vinho));

  cout << "\nDigite o nome do vinho: ";
  cin.ignore();
  fgets(novo->nome, 30, stdin);
  fflush(stdin);
  
  int temp = 0;
  for(int i = 0; novo->nome[i] != '\0'; i++){
  temp++;}
  novo->nome[temp-1] = '\0';
  
  cout << "\nDigite o país de origem: ";
  cin >> novo->pais;
  
  cout << "\nDigite o tipo da uva: ";
  cin.ignore();
  fgets(novo->tipo, 30, stdin);
  fflush(stdin);
  
  temp = 0;
  for(int i = 0; novo->tipo[i] != '\0'; i++){
  temp++;}
  novo->tipo[temp-1] = '\0';
  
  cout << "\nDigite o ano da safra: ";
  cin >> novo->safra;
  
  if(first == NULL){

    first = novo;
    last = novo;
    novo->prev = NULL;
    novo->next = NULL;
    cout << "\n\nVinho adicionado com sucesso à adega!\n";
  }

  else{
    
    novo->prev = last;
    novo->next = NULL;
    last->next = novo;
    last = novo;
    cout << "\n\nVinho adicionado com sucesso à adega!\n";
  }

}

void remov(vinho *& first, vinho *& last){
  
  system("clear||cls");
  
  int flag = 0;
  if(first != NULL && last != NULL){
    
  cout << "\n\nÉ uma ocasião especial?\n\n0 - Não\n1 - Sim\n";
  cin >> flag;

  if(flag == 0){
    
    cout << "\n\nO vinho " << first->nome << " deve ser retirado da adega!\nDeseja retira-lo?\n\n0 - Não\n1 - Sim\n";
    cin >> flag;
    
    if(flag == 1){
     vinho *aux = first;

     if(aux->next != NULL){ 
     first = aux->next;
     first->prev = NULL;}
      
     cout << "\nVinho " << aux->nome << " retirado da adega!\n";
     if(aux->next == NULL){
       first = NULL;
       last = NULL;
     } 
     else{ 
     free(aux);
     }
    }

    else if (flag == 0){
     return; 
  }

      else{
        cout << "Valor não definido!\n";
      }

    }
    
  else if(flag == 1){
    
    cout << "\n\nO vinho " << last->nome << " deve ser retirado da adega!\nDeseja retira-lo?\n\n0 - Não\n1 - Sim\n";
    cin >> flag;
    
    if(flag == 1){
     vinho *aux = last;
      if(aux->prev != NULL){
      last = aux->prev;
      last->next = NULL;
      }
      
     cout << "Vinho " << aux->nome << " retirado da adega!\n";
      
      if(aux->prev == NULL){
        
        last = NULL;
        first = NULL;
     } 
     else{ 
     free(aux);
    }
    }
    else if (flag == 0){
     return; 
  }

      else{
        cout << "Valor não definido!\n";
      }

    }
      
  else{
    cout << "Valor não definido!\n";
  }

    }
  else{
    cout<<"Não há vinhos na adega!\n";
    }
  
  

  
}

void list (vinho *& first, vinho *& last){
  system("clear||cls");

  
  if(first != NULL && last != NULL){
  vinho *aux;

  //Listar 5 primeiros//

  aux = last;
  cout << "Mais recentes:\n\n";
  cout << "\tNOME\t\t\t|\t\tPAÍS\t\t|\t\t\tTIPO\t\t|\t\tSAFRA\n";
  for (int i=0; i<5; i++){
    
      cout << "\t" << aux->nome;
      cout << "\t|\t\t" << aux->pais;
      cout << "\t";
      cout << "\t|\t\t\t" << aux->tipo;
      cout << "\t\t|\t\t" << aux->safra << "\n";
      aux = aux->prev;
      
      }
    //Listar 5 ultimos//

  aux = first;
  cout << "\n\n\nMais antigos:\n\n";
    cout << "\tNOME\t\t\t|\t\tPAÍS\t\t|\t\t\tTIPO\t\t|\t\tSAFRA\n";
  for (int i=0; i<5; i++){
   
     cout << "\t" << aux->nome;
      cout << "\t|\t\t" << aux->pais;
      cout << "\t";
      cout << "\t|\t\t\t" << aux->tipo;
      cout << "\t\t|\t\t" << aux->safra << "\n";
      aux = aux->next;
    }
  
  }
  
  else{
    cout<<"Não há vinhos na adega!\n";
    }
  }

int main() {
  
  string sair;
  vinho *first = NULL;
  vinho *last = NULL;

  bool exit = false;
  while(exit != true) {  
  switch(menu()) {
    case 1:
    aloc(first, last);
    cout << "\n\nPressione qualquer tecla para voltar ao menu principal\n";
    cin >> sair;
  break;

    case 2:
    remov(first, last);  
    cout << "\n\nPressione qualquer tecla para voltar ao menu principal\n";
    cin >> sair;
    break;

    case 3:
    list(first, last);
    cout << "\n\nPressione qualquer tecla para voltar ao menu principal\n";
    cin >> sair;
    break;
    
    case 4:
    exit = true;
    break;
    default:
    cout<<"\n\nOPÇÃO INVALIDA!\n\n";
    cout << "\n\nPressione qualquer tecla para voltar ao menu principal\n";
    cin >> sair;
    break;
    
  }  
 }
  system("clear||cls");
  cout << "Programa encerrado!";
}

