#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
 
int main() {
    int numerosSorteados[6];
    int minimo = 1;
    int maximo = 10;
 
    srand(time(NULL));
 
    for (int i = 0; i < 6; i++) {
        bool repetido;
 
        do {
            repetido = false;
            int novoNumero = rand() % (maximo - minimo + 1) + minimo;
 
            for (int j = 0; j < i; j++) {
                if (numerosSorteados[j] == novoNumero) {
                    repetido = true;
                    break;
                }
            }
 
            if (!repetido) {
                numerosSorteados[i] = novoNumero;
            }
        } while (repetido);
    }
 
    int baixo = 0;
    int alto = 5;
 
    int stack[6];
    int topo = -1;
 
    stack[++topo] = baixo;
    stack[++topo] = alto;
 
    while (topo >= 0) {
        alto = stack[topo--];
        baixo = stack[topo--];
 
        int pivo = numerosSorteados[alto];
        int i = (baixo - 1);
 
        for (int j = baixo; j <= alto - 1; j++) {
            if (numerosSorteados[j] < pivo) {
                i++;
                int temporaria = numerosSorteados[i];
                numerosSorteados[i] = numerosSorteados[j];
                numerosSorteados[j] = temporaria;
            }
        }
 
        int temporaria = numerosSorteados[i + 1];
        numerosSorteados[i + 1] = numerosSorteados[alto];
        numerosSorteados[alto] = temporaria;
 
        int pi = i + 1;
 
        if (pi - 1 > baixo) {
            stack[++topo] = baixo;
            stack[++topo] = pi - 1;
        }
 
        if (pi + 1 < alto) {
            stack[++topo] = pi + 1;
            stack[++topo] = alto;
        }
    }
 
    printf("Os numeros que foram sorteados sao: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", numerosSorteados[i]);
    }
    printf("\n");
 
    return 0;
}