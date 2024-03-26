#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int numerosRandomicos() {
    // Gera números de 0 a 200
    return rand() % 200;
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

// Ordena a lista pelo conceito do shell sort
void shell_sort(int *lista, int tamanho) {
    // Primeiro: calculamos o k (num de varreduras)
    float k = log(tamanho + 1) / log(3); // Com base na fórmula de Donald Ervin Knuth
    k = floor(k+0.5);

    // Segundo: calculamos a distância inicial
    int h = (pow(3,k)-1) / 2; // Fórmula de Donald Ervin Knuth

    while(h > 0) {

        for(int i = 0; i < tamanho - h; i++) {
            int aux;
            if(lista[i] > lista[i + h]) {
                aux = lista[i];
                lista[i] = lista[i + h];
                lista[i + h] = aux;

                int j = i;
                while(j - h >= 0 ) {
                    if(lista[j] < lista[j - h]) {
                        aux = lista[j];
                        lista[j] = lista[j - h];
                        lista[j - h] = aux;
                    }
                    j = j - h;
                }
            }
        }
        k--;
        h = (pow(3,k)-1) / 2;
    }

}

int main() { 
    // Inicialização para geração de números aleatórios e medição de tempo de execução
    time_t t;  clock_t tempo; 
    srand((unsigned) time(&t));

    int tamanho = 50;
    int lista[tamanho];
    setaLista(lista, tamanho);
    
    printf("\nLista Inicial: \n");
    printaLista(lista, tamanho);


    printf("\n\nLista Ordenada: \n");
    
    tempo = clock(); //armazena tempo
    shell_sort(lista, tamanho);
    tempo = clock() - tempo; //tempo final - tempo inicial
    
    printaLista(lista, tamanho);

    // Printa o tempo de execução do algoritmo em milisegundos
    printf("\n\nTempo de execucao: %lf", ((double)tempo)/((CLOCKS_PER_SEC/1000))); 
}