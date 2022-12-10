#include <iostream>
using namespace std;

struct vinho{
char nome[30];
char pais[30];
char tipo[30];
int safra;
vinho *prox;
vinho *ant;
};

int menu(){
  system("clear||cls");
  int opcao;

  
  cout << "          **  VINÍCOLA DOS TRALHAS  **       v6.9\n\n";
  
  cout << "Digite 1 para adicionar vinhos à adega;\n\nDigite 2 para remover vinhos da adega\n\nDigite 3 para listar as primeiras e ultimas adições\n\nDigite 4 para encerrar o programa\n";

  
  cin>>opcao;
  
  return opcao;
}

void add(vinho *& primeiro, vinho *& ultimo){
system("clear||cls");
  vinho *novo;
  novo = (vinho*) calloc (1, sizeof(vinho));

  cout << "\nDigite o nome do vinho: ";
  cin >> novo->nome;
  
  cout << "\nDigite o país de origem: ";
  cin >> novo->pais;
  
  cout << "\nDigite o tipo da uva: ";
  cin.ignore();
  fgets(novo->tipo, 30, stdin);
  fflush(stdin);
  
  int temp = 0;
  for(int i = 0; novo->tipo[i] != '\0'; i++){
  temp++;}
  novo->tipo[temp-1] = '\0';
  
  cout << "\nDigite o ano da safra: ";
  cin >> novo->safra;
  
  if(primeiro == NULL){

    primeiro = novo;
    ultimo = novo;
    novo->ant = NULL;
    novo->prox = NULL;
    cout << "\n\nVinho adicionado com sucesso à adega!\n";
  }

  else{
    
    novo->ant = ultimo;
    novo->prox = NULL;
    ultimo->prox = novo;
    ultimo = novo;
    cout << "\n\nVinho adicionado com sucesso à adega!\n";
  }

}

void retirar(vinho *& primeiro, vinho *& ultimo){
  
  system("clear||cls");
  
  int flag = 0;
  if(primeiro != NULL && ultimo != NULL){
    
  cout << "\n\nÉ uma ocasião especial?\n\n0 - Não\n1 - Sim\n";
  cin >> flag;

  if(flag == 0){
    
    cout << "\n\nO vinho " << primeiro->nome << " deve ser retirado da adega!\nDeseja retira-lo?\n\n0 - Não\n1 - Sim\n";
    cin >> flag;
    
    if(flag == 1){
     vinho *aux = primeiro;

     if(aux->prox != NULL){ 
     primeiro = aux->prox;
     primeiro->ant = NULL;}
      
     cout << "\nVinho " << aux->nome << " retirado da adega!\n";
     if(aux->prox == NULL){
       primeiro = NULL;
       ultimo = NULL;
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
    
    cout << "\n\nO vinho " << ultimo->nome << " deve ser retirado da adega!\nDeseja retira-lo?\n\n0 - Não\n1 - Sim\n";
    cin >> flag;
    
    if(flag == 1){
     vinho *aux = ultimo;
      if(aux->ant != NULL){
      ultimo = aux->ant;
      ultimo->prox = NULL;
      }
      
     cout << "Vinho " << aux->nome << " retirado da adega!\n";
      
      if(aux->ant == NULL){
        
        ultimo = NULL;
        primeiro = NULL;
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

void listar (vinho *& primeiro, vinho *& ultimo){
  system("clear||cls");

  
  if(primeiro != NULL && ultimo != NULL){
  vinho *aux;

  //Listar 5 primeiros//

  aux = ultimo;
  cout << "Mais recentes:\n\n";
  cout << "\tNOME\t\t|\t\tPAÍS\t\t|\t\tTIPO\t\t|\t\tSAFRA\n";
  for (int i=0; i<5; i++){
    if(aux==NULL){
      
    }
      
    else{
      cout << "\t" << aux->nome;
      cout << "\t\t|\t\t" << aux->pais;
      cout << "\t\t|\t\t" << aux->tipo;
      cout << "\t\t|\t\t" << aux->safra << "\n";
      aux = aux->ant;
    }
  }

    //Listar 5 ultimos//

  aux = primeiro;
  cout << "\n\n\nMais antigos:\n\n";
    cout << "\tNOME\t\t|\t\tPAÍS\t\t|\t\tTIPO\t\t|\t\tSAFRA\n";
  for (int i=0; i<5; i++){
    if(aux==NULL){
      
    }
    else{
      cout << "\t" << aux->nome;
      cout << "\t\t|\t\t" << aux->pais;
      cout << "\t\t|\t\t" << aux->tipo;
      cout << "\t\t|\t\t" << aux->safra << "\n";
      aux = aux->prox;
    }
  }

  }
  else{
    cout<<"Não há vinhos na adega!\n";
    }
  
}

int main() {
  
  string sair;
  vinho *primeiro = NULL;
  vinho *ultimo = NULL;

  bool exit = false;
  while(exit != true) {  
  switch(menu()) {
    case 1:
    add(primeiro, ultimo);
    cout << "\n\nPressione qualquer tecla para voltar ao menu principal\n";
    cin >> sair;
  break;

    case 2:
    retirar(primeiro, ultimo);  
    cout << "\n\nPressione qualquer tecla para voltar ao menu principal\n";
    cin >> sair;
    break;

    case 3:
    listar(primeiro, ultimo);
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

