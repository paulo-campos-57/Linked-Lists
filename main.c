#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int valor;
  struct Node *next;
} Node;

void insertNode(Node **head, int valor);
void insertEnd(Node **head, int valor);
void removeNode(Node **head);
void removeEnd(Node **head);
int checkNumber(Node *head, int valor);
int listSize(Node *head);
void listPrint(Node *head);
void menu();

int main(void) {

  Node *head = NULL;
  int op = -1;
  int valor;
  int size;
  int verificador;

  do {
    menu();
    scanf("%d", &op);

    switch (op) {
    case 1:
      printf("Informe o valor: ");
      scanf("%d", &valor);
      insertNode(&head, valor);
      break;
    case 2:
      printf("Informe o valor: ");
      scanf("%d", &valor);
      insertEnd(&head, valor);
      break;
    case 3:
      removeNode(&head);
      break;
    case 4:
      removeEnd(&head);
      break;
    case 5:
      printf("Informe o valor para verificar se ele está na lista: ");
      scanf("%d", &valor);
      verificador = checkNumber(head, valor);
      if (verificador == 2) {
        printf("\n");
      } else if (verificador == 0) {
        printf("\nEsse valor não está na lista!\n");
      } else if (verificador == 1) {
        printf("\nEsse valor está na lista!\n");
      }
      break;
    case 6:
      size = listSize(head);
      if (size == 0) {
        printf("\n");
      } else {
        printf("A lista contém %d elementos!\n", size);
      }
      break;
    case 7:
      listPrint(head);
      break;
    case 0:
      printf("\nOperação encerrada.\n");
      break;
    default:
      printf("\nOpção inválida\n");
      break;
    }
  } while (op != 0);

  return 0;
}

// Funções de Inserção
void insertNode(Node **head, int valor) {
  Node *novo = (Node *)malloc(sizeof(Node));

  if (novo != NULL) {
    novo->valor = valor;
    novo->next = *head;
    *head = novo;
    printf("Valor inserido com sucesso!\n");
  } else {
    printf("Erro na alocação de memória!\n");
    return;
  }
}

void insertEnd(Node **head, int valor) {
  Node *novo = (Node *)malloc(sizeof(Node));

  if (novo != NULL) {
    novo->valor = valor;
    novo->next = NULL;
    if (head == NULL) {
      *head = novo;
      printf("Valor inserido com sucesso!\n");
      return;
    } else {
      Node *temp = *head;
      while (temp->next != NULL) {
        temp = temp->next;
      }
      temp->next = novo;
      printf("Valor inserido com sucesso!\n");
    }
  } else {
    printf("Erro na alocação de memória!\n");
    return;
  }
}
/*---------------------------------------------------------*/

// Funções de Remoção
void removeNode(Node **head) {
  Node *temp;
  if (head != NULL) {
    temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("Valor removido com sucesso!\n");
  } else {
    printf("\nA lista está vazia!\n");
    return;
  }
}

void removeEnd(Node **head) {
  if (head != NULL) {
    if ((*head)->next == NULL) {
      free(*head);
      *head = NULL;
      printf("Valor removido com sucesso!\n");
    } else {
      Node *temp = *head;
      while (temp->next->next != NULL) {
        temp = temp->next;
      }
      free(temp->next);
      temp->next = NULL;
      printf("Valor removido com sucesso!\n");
    }
  } else {
    printf("\nA lista está vazia!\n");
    return;
  }
}
/*---------------------------------------------------------*/

// Funções auxiliares
int checkNumber(Node *head, int valor) {
  if (head == NULL) {
    printf("\nA lista está vazia!\n");
    return 2;
  } else {
    while (head != NULL) {
      if (head->valor == valor) {
        return 1;
      }
      head = head->next;
    }
    return 0;
  }
}

int listSize(Node *head) {
  if (head == NULL) {
    printf("\nA lista está vazia!\n");
    return 0;
  } else {
    int contador = 0;
    while (head != NULL) {
      head = head->next;
      contador++;
    }
    return contador;
  }
}

void listPrint(Node *head) {
  if (head == NULL) {
    printf("\nA lista está vazia!\n");
    return;
  }
  while (head != NULL) {
    printf("%d -> ", head->valor);
    head = head->next;
  }
  printf("NULL\n");
}
/*---------------------------------------------------------*/

// Funções de Interface
void menu() {
  printf("----------MENU----------\n\n");
  printf("1 - Inserir elemento na lista\n");
  printf("2 - Inserir elemento no final da lista\n");
  printf("3 - Remover elemento da lista\n");
  printf("4 - Remover elemento no final da lista\n");
  printf("5 - Verificar se um número está na lista\n");
  printf("6 - Quantos elementos estão presentes na lista\n");
  printf("7 - Imprimir todos os elementos da lista\n");
  printf("0 - SAIR\n\n");
}
/*---------------------------------------------------------*/
