#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int numerosRandomicos() {
    // Gera números de 0 a 100000
    return rand() % 100000;
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

// Ordena a lista pelo conceito do insertion sort
void insertion_sort(int *lista, int tamanho) {
    for(int i = 1; i < tamanho; i++) {
        for(int j = i; j > 0; j --) {
            int aux;
            
            /*
            * Caso o elemento da esquerda seja maior que o elemento sendo analisado, faço a troca.
            * Por ser um insertion sort, se eu não fizer uma troca é por que o elemento da esquerda já é menor, então já está ordenado 
            * daquele elemento para trás e com isso não preciso continuar o loop
            */ 
            
            if(lista[j] < lista[j - 1]) {
                aux = lista[j];
                lista[j] = lista[j - 1];
                lista[j - 1] = aux;
            } else break;
        }

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
    insertion_sort(lista, tamanho);
    tempo = clock() - tempo; //tempo final - tempo inicial
    
    printaLista(lista, tamanho);

    // Printa o tempo de execução do algoritmo em milisegundos
    printf("\n\nTempo de execucao: %lf", ((double)tempo)/((CLOCKS_PER_SEC/1000))); 
}