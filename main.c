#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

typedef struct Veiculo {
  char proprietario[20];
  char combustivel[8];
  char modelo[20];
  char cor[10];
  char numChassi[17];
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

  printf("Informe o nome do proprietário: ");
  clearBuffer();
  fgets(novoVeiculo->proprietario, 20, stdin);
  printf("%s", novoVeiculo->proprietario);
  
  printf("Selecione o tipo de combustível: \n");
  do 
  {
    printf("0. álcool\n");
    printf("1. diesel\n");
    printf("2. gasolina\n");
    printf("opção escolhida: ");
    scanf("%d", &option);
  }
  while(option != 1 && option != 2 && option != 3);
  
  strcpy(novoVeiculo->combustivel, tipoCombustivel[option]);

  printf("Digite o modelo do veiculo: ");
  clearBuffer();
  fgets(novoVeiculo->modelo, 20, stdin);

  printf("Digite a cor: ");
  fgets(novoVeiculo->cor, 10, stdin);
  
  printf("Digite o numero do chassi: ");
  fgets(novoVeiculo->numChassi, 18, stdin);
  
  printf("Digite o ano do veiculo: ");
  scanf("%d", &novoVeiculo->ano);
  
  printf("Digite a placa do veiculo: ");
  clearBuffer();
  fgets(novoVeiculo->placa, 8, stdin);
  
  for(i = 0; i < 3; i++)
    novoVeiculo->placa[i] = toupper(novoVeiculo->placa[i]);


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

void placasDiesel2010(Veiculo *lista)
{
  printf("\nVeiculos a partir de 2010 a diesel\n");
  while(lista != NULL)
  {
    if(lista->ano >= 2010 && strcmp(lista->combustivel, "diesel") == 0)
    {
      printf("\nproprietário: %s", lista->proprietario);
      printf("\nano: %d\n", lista->ano);
    }

    lista = lista->prox;
  }
}

void placasJ(Veiculo* lista) {
    printf("\nProprietarios:\n");

    while (lista != NULL) 
    {
      if(lista->placa[0] == 'J' && 
        (lista->placa[6] == '0'|| 
         lista->placa[6] == '2' || 
         lista->placa[6] == '4' || 
         lista->placa[6] == '7')) 
            printf("Placa: %s, Proprietario: %s\n", lista->placa, lista->proprietario);
      
        lista = lista->prox;
    }
}

void verificarVogalSoma(Veiculo* lista) 
{
  printf("\nModelo e cor dos veiculos com placas 2nd letra vogal e soma par\n");

  char vogais[] = {'A', 'E', 'I', 'O', 'U'};
  int somaNumsPlaca = 0, i;

  for(i = 3; i < 7; i++)
    somaNumsPlaca += lista->placa[i];

  while (lista != NULL) {
    for(i = 0; i < 5; i++)
    {
      if(lista->placa[1] == vogais[i] && (somaNumsPlaca % 2) == 0)
      {
          printf("Modelo: %s\n", lista->modelo);
          printf("Cor: %s", lista->cor);
      }
    }
    
    lista = lista->prox;
  }
}

void trocarProprietario(Veiculo* lista) {
  Veiculo* atual = lista;
  char chassiTroca[17];
  int i;

  clearBuffer();
  printf("\nDigite o numero do chassi para troca de proprietario: ");
  fgets(chassiTroca, 18, stdin);


  while (atual != NULL) {
    if(strcmp(atual->numChassi, chassiTroca) == 0)
    {
      for(i = 3; i < 7; i++)
        if(atual->placa[i] != 0)
        {
          printf("digite o nome do novo proprietário: ");
          clearBuffer();
          fgets(atual->proprietario, 20, stdin);
          printf("Proprietario alterado com sucesso.\n");
          return;
        }
        else
        {
          printf("Placa possui digito zero, impossivel trocar proprietario do veiculo.\n");
          return;
        }   
    }
    atual = atual->prox;
  }

  printf("Nenhum veiculo encontrado com o numero do chassi fornecido.");
}

void mostrarOpcoes() {
  printf("\npara continuar selecione uma opção\n");

  printf("1. registrar veiculo\n");
  printf("2. veiculos a partir de 2010 a diesel\n");
  printf("3. placas que comecem com J e termine com 0, 2, 4 ou 7\n");
  printf("4. placas com segunda letra uma vogal e a soma dos numeros dê par\n");
  printf("5. trocar proprietário\n");
  printf("0. SAIR\n");
};

int main() {
  Veiculo *lista = inicializarLista();
  int option;
  
  do
  {
    mostrarOpcoes();
    printf("digite a opção escolhida: ");
    scanf("%d", &option);
    switch(option)
    {
      case 1:
        lista = cadastrar(lista);
        break;
      case 2:
        placasDiesel2010(lista);
        break;
      case 3:
        placasJ(lista);
        break;
      case 4:
        verificarVogalSoma(lista);
      break;
      case 5:
        trocarProprietario(lista);
      break;
      default:
        printf("opção inválida!");
    }
    sleep(3);
  }
  while(option != 0);
  
  return 0;
};
