#include <stdio.h>

int main() {
    int n;
    printf("--- Questao 03: A Razao de Eficiencia de um Numero ---\n");
    printf("Digite um numero inteiro N (1 <= N <= 105): ");
    scanf("%d", &n);

    if (n < 1 || n > 105) {
        printf("Numero fora do intervalo permitido.\n");
        return 1;
    }

}