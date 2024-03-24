#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int numerosRandomicos() {
    // Gera números de 0 a 100000
    return rand() % 10000;
}

// Preenche a lista com valores randômicos
void setaLista(int *lista, int tamanho) {
    for(int i = 0; i < tamanho; i++) 
        lista[i] = numerosRandomicos();
}

// Apenas printa na tela a lista como está atualmente
void printaLista(int *lista, int tamanho) {
    for(int i = 0; i < tamanho; i++) 
        printf("%d ", lista[i]);
}

// Ordena a lista pelo conceito do selection sort
void selection_sort(int *lista, int tamanho) {
    for(int i = 0; i < tamanho - 1; i++) {
        int aux;
        int indiceMenor = i;
        for(int j = i+1; j < tamanho; j++) {
            if(lista[j] < lista[indiceMenor]) {
                indiceMenor = j;
            }
        }
        aux = lista[i];
        lista[i] = lista[indiceMenor];
        lista[indiceMenor] = aux;
    }
}

int main() {
    // Inicialização para geração de números aleatórios e medição de tempo de execução
    time_t t;  clock_t tempo; 
    srand((unsigned) time(&t));

    int tamanho = 1000;
    int lista[tamanho];
    setaLista(lista, tamanho);
    
    printf("\nLista Inicial: \n");
    printaLista(lista, tamanho);


    printf("\n\nLista Ordenada: \n");
    
    tempo = clock(); //armazena tempo
    selection_sort(lista, tamanho);
    tempo = clock() - tempo; //tempo final - tempo inicial
    
    printaLista(lista, tamanho);

    // Printa o tempo de execução do algoritmo em milisegundos
    printf("\n\nTempo de execucao: %lf", ((double)tempo)/((CLOCKS_PER_SEC/1000))); 
}