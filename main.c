#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Veiculo {
  char proprietario[20];
  char combustivel[8];
  char modelo[20];
  char cor[10];
  long int numChassi;
  int ano;
  char placa[7];
  struct Veiculo *prox;
} Veiculo;

void clearBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
};

Veiculo *inicializarLista() {
  return NULL;
};

Veiculo *criarVeiculo()
{
  Veiculo *novoVeiculo = (Veiculo*)malloc(sizeof(Veiculo));

  if(novoVeiculo == NULL)
  {
    printf("Erro de alocação");
    exit(EXIT_FAILURE);
  }
  novoVeiculo->prox = NULL;
  return novoVeiculo;
};

Veiculo *cadastrar(Veiculo *lista)
{
  Veiculo *novoVeiculo = criarVeiculo();
  char tipoCombustivel[3][8] = {"alcool", "diesel", "gasolina"};
  int i, option;

  printf("\nDigite o proprietário do veiculo: ");
  fgets(novoVeiculo->proprietario, 20, stdin);
  
  printf("\nSelecione o tipo de combustível: \n");
  
  do 
  {
    printf("0. álcool\n");
    printf("1. diesel\n");
    printf("2. gasolina\n");
    scanf("%d", &option);
  }
  while(option != 0 && option != 1 && option != 2);
  strcpy(novoVeiculo->combustivel, tipoCombustivel[option]);

  //printf("\nDigite o modelo do veiculo: ");
  //fgets(novoVeiculo->modelo, 20, stdin);
  strcpy(novoVeiculo->cor, "honda");

  printf("\nDigite a cor: ");
  //fgets(novoVeiculo->cor, 10, stdin);
  strcpy(novoVeiculo->cor, "azul");
  
  printf("\nDigite o numero do chassi: ");
  //scanf("%d", &novoVeiculo->numChassi);
  novoVeiculo->numChassi = 12345678912345678;

  printf("\nDigite o ano do veiculo: ");
  scanf("%d", &novoVeiculo->ano);

  clearBuffer();
  
  printf("\nDigite a placa do veiculo: ");
  fgets(novoVeiculo->placa, 7, stdin);

  //for(i = 0; i < 7; i++)
  //{
    //if(isalpha(novoVeiculo->placa[i]))
    //{
      //printf("é letra\n");
    //}
    //else
    //{
     //printf("é número\n");
    //}
      
  //}
  clearBuffer();


  if(lista == NULL)
    return novoVeiculo;
  else
  {
    Veiculo *atual = lista;
    while(atual->prox != NULL)
    {
      atual = atual->prox;
    }
    atual->prox = novoVeiculo;
    return lista;
  }
}

void listarVeiculos(Veiculo *lista)
{
  int i = 1;
  printf("Veiculos a partir de 2010 a diesel\n");
  
  while(lista != NULL)
  {
    if(lista->ano >= 2010 && strcmp(lista->combustivel, "diesel") == 0)
    {
      printf("proprietário: %s\n", lista->proprietario);
      printf("ano: %d\n", lista->ano);
      printf("combustivel: %s\n", lista->combustivel);
    }

    lista = lista->prox;
    i++;
  }
}

Veiculo mockVeiculos(Veiculo *lista)
{
  int i = 0;
  while(i < 2)
  {
      lista = cadastrar(lista);
      i++;
  }
};

void mostrarOpcoes() {
  printf("\npara continuar selecione uma opção\n");
  printf("1. carros a partir de 2010 a diesel\n");
  printf("2. placas que comecem com J e termine com 0, 2, 4 ou 7\n");
  printf("3. placas com segunda letra uma vogal e a soma dos numeros dê par\n");
  printf("4. trocar proprietário\n");
};

int main() {
  Veiculo *lista = inicializarLista();
  
  //mostrarOpcoes();
  mockVeiculos(lista);
  listarVeiculos(lista);
  
  return 0;
};
