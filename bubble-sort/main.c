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

// Ordena a lista pelo conceito do bubble sort
void bubble_sort(int *lista, int tamanho) {
    
    for(int i = tamanho - 1; i > 0; i--) {
        int trocas = 0;
        
        for(int j = 0; j < i; j++) {
            int aux;    
            if(lista[j] > lista[j + 1]) {
                aux = lista[j + 1];
                lista[j + 1] = lista[j];
                lista[j] = aux;

                trocas++;
            }
        }

        // Se não houver nenhuma troca, então a lista já está ordenada
        if (trocas == 0) break;
    }
}

int main() {
    // Inicialização para geração de números aleatórios e medição de tempo de execução
    time_t t;  clock_t tempo; 
    srand((unsigned) time(&t));

    int tamanho = 5000;
    int lista[tamanho];
    setaLista(lista, tamanho);
    
    printf("\nLista Inicial: \n");
    printaLista(lista, tamanho);


    printf("\n\nLista Ordenada: \n");
    
    tempo = clock(); //armazena tempo
    bubble_sort(lista, tamanho);
    tempo = clock() - tempo; //tempo final - tempo inicial
    
    printaLista(lista, tamanho);

    // Printa o tempo de execução do algoritmo em milisegundos
    printf("\n\nTempo de execucao: %lf", ((double)tempo)/((CLOCKS_PER_SEC/1000))); 
}