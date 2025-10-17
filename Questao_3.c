#include <stdio.h>

long long integer_pow(int base, int expoente) {
    long long resultado = 1;
    for (int i = 0; i < expoente; i++) {
        resultado *= base;
    }
    return resultado;

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

        // --- Passo 2: Cálculo de tau(N) e sigma(N) ---
    long long tau_n = 1;
    long long sigma_n = 1;

    // Calcula tau(N) e sigma(N)
    for (int i = 0; i < numFatoresDistintos; i++) {
        int p = fatoresPrimos[i];
        int a = expoentes[i];
        
        tau_n *= (a + 1);
        sigma_n *= (integer_pow(p, a + 1) - 1) / (p - 1);
    }
    
    // Tratamento especial para N=1
    if (n == 1) {
        tau_n = 1;
        sigma_n = 1;
    }

    printf("\n--- Passo 2: Calculo de tau(N) e sigma(N) ---\n");
    printf("Calculo de tau(N) (numero de divisores): %lld\n", tau_n);
    printf("Calculo de sigma(N) (soma dos divisores): %lld\n", sigma_n);

        // --- Passo 3: Cálculo da Razão de Eficiência ---
    double razao = 0.0;
    if (tau_n != 0) {
        // Cast para double para garantir a divisão de ponto flutuante
        razao = (double)sigma_n / tau_n;
    }

    printf("\n--- Passo 3: Resultado Final ---\n");
    // Usando "%.2f" no printf para formatar com 2 casas decimais
    printf("A Razao de Eficiencia de %d e: %.2f\n", n, razao);

    return 0;
}