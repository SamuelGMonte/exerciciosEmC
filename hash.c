#include <stdio.h>
#include <stdlib.h>

int* array;
int size;

int hash(int val) {
    return val % size;
}

void init() {
    int i;
    for (i = 0; i < size; i++) {
        array[i] = -1;
    }
}

void insert(int val) {
    int key = hash(val);
    if (array[key] == -1) { 
        array[key] = val;
    }
    else {
        printf("Colisao, valor %d na posicao array[%d] ja existente\n", val, key);
    }
}


void search(int val) {
    int i;
    int key = hash(val);
        if (array[key] == -1) {
            printf("valor %d nao encontrado\n", val);
        }
        else {
            printf("valor na posicao %d e %d\n", key, array[key]);
        }
}


void printHash() {
    int i;
    for (i = 0; i < size; i++) {
        printf("array[%d]: %d\n", i, array[i]);
    }
}


int main() {
    int num;

    printf("Digite a quantidade de elementos da tabela hash: ");
    scanf("%d", &size);

    array = (int*) malloc(sizeof(int) * size);

    if (array == NULL) {
        printf("Tamanho nulo, erro");
        return -1;
    }

    init();

    printf("Escreva o numero que voce deseja inserir na tabela hash: \n");
    scanf("%d", &num);

    insert(num);


    printf("Escreva o numero que voce deseja buscar na tabela hash: \n");
    scanf("%d", &num);

    search(num);

    printf("Valor da tabela apos modificacoes: \n");
    printHash();


    return 0;
}
