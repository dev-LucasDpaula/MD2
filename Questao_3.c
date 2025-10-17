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

    // --- Passo 1: Fatoracao Prima de N ---
    printf("\n--- Passo 1: Fatoracao Prima de %d ---\n", n);

    // Arrays estáticos para armazenar os fatores e seus expoentes
    int fatoresPrimos[32];
    int expoentes[32];
    int numFatoresDistintos = 0;
    int n_temp = n; // Variável temporária para a fatoração

    // Trata o fator 2
    int contador = 0;
    while (n_temp % 2 == 0) {
        contador++;
        n_temp /= 2;
    }
    if (contador > 0) {
        fatoresPrimos[numFatoresDistintos] = 2;
        expoentes[numFatoresDistintos] = contador;
        numFatoresDistintos++;
        printf("Fator primo encontrado: 2, Expoente: %d\n", contador);
    }

    // Trata os fatores ímpares. Usamos i*i <= n_temp em vez de i <= sqrt(n_temp)
    for (int i = 3; i * i <= n_temp; i += 2) {
        contador = 0;
        while (n_temp % i == 0) {
            contador++;
            n_temp /= i;
        }
        if (contador > 0) {
            fatoresPrimos[numFatoresDistintos] = i;
            expoentes[numFatoresDistintos] = contador;
            numFatoresDistintos++;
            printf("Fator primo encontrado: %d, Expoente: %d\n", i, contador);
        }
    }

    // Se n_temp ainda for maior que 2, o que restou é um fator primo
    if (n_temp > 2) {
        fatoresPrimos[numFatoresDistintos] = n_temp;
        expoentes[numFatoresDistintos] = 1;
        numFatoresDistintos++;
        printf("Fator primo encontrado: %d, Expoente: 1\n", n_temp);
    }
    
    if (n == 1) {
         printf("O numero 1 nao possui fatores primos.\n");
    }


}