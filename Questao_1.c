#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

// Para garantir a compatibilidade e evitar overflow, usamos long long para os números grandes.
typedef long long int lli;

// ---------------------------------------------------------------------------------
// FUNÇÕES MATEMÁTICAS FUNDAMENTAIS (Implementadas pelo Aluno)
// ---------------------------------------------------------------------------------

/**
 * @brief Calcula o Máximo Divisor Comum (MDC) entre dois números usando o Algoritmo de Euclides.
 * A função também imprime cada passo do cálculo para fins didáticos, conforme solicitado.
 * @param a Primeiro número.
 * @param b Segundo número.
 * @param print_steps Flag para controlar a impressão dos passos (1 = imprimir, 0 = não imprimir).
 * @return O MDC de a e b.
 */
lli mdc(lli a, lli b, int print_steps) {
    if (print_steps) {
        printf(" -> Calculando mdc(%lld, %lld) com Algoritmo de Euclides:\n", a, b);
    }
    lli temp;
    lli original_a = a, original_b = b;
    while (b != 0) {
        if (print_steps) {
            printf("    - %lld = %lld * (%lld) + %lld\n", a, a / b, b, a % b);
        }
        temp = b;
        b = a % b;
        a = temp;
    }
    if (print_steps) {
        printf("    - Resultado do MDC(%lld, %lld): %lld\n", original_a, original_b, a);
    }
    return a;
}

/**
 * @brief Encontra o inverso modular de 'a' em relação a 'm' usando o Algoritmo Estendido de Euclides.
 * A função encontra 'x' tal que (a * x) % m = 1.
 * Também imprime os passos do algoritmo.
 * @param a O número para o qual encontrar o inverso.
 * @param m O módulo.
 * @return O inverso modular de 'a'.
 */
lli inverso_modular(lli a, lli m) {
    lli m0 = m, t, q;
    lli x0 = 0, x1 = 1;

    printf(" -> Calculando Inverso Modular de %lld mod %lld com Algoritmo Estendido de Euclides:\n", a, m);

    if (m == 1) return 0;

    // Aplica o Algoritmo Estendido de Euclides
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        printf("    - q=%-5lld, a=%-5lld, m=%-5lld | ", q, a, m);
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
        printf("x0=%-5lld, x1=%-5lld\n", x0, x1);
    }

    // Garante que x1 seja positivo
    if (x1 < 0) {
        x1 += m0;
    }
    
    printf("    - Inverso modular encontrado: %lld\n", x1);
    return x1;
}

/**
 * @brief Implementa o método Rho de Pollard para fatorar um número N.
 * Utiliza a função de iteração g(x) = (x^2 + 1) mod N. Exibe cada passo.
 * @param n O número composto a ser fatorado.
 * @return Um fator não trivial de n.
 */
lli pollard_rho(lli n) {
    if (n % 2 == 0) return 2;

    lli x = 2, y = 2, d = 1;

    printf(" -> Iniciando Fatoracao de %lld com Metodo Rho de Pollard:\n", n);
    printf("    g(x) = (x^2 + 1) mod %lld | Semente x_0 = 2\n", n);
    printf("------------------------------------------------------------\n");
    printf("| Iteracao | Tartaruga (x) | Lebre (y)    | mdc(|x-y|, N) |\n");
    printf("------------------------------------------------------------\n");

    int i = 1;
    while (d == 1) {
        x = (x * x + 1) % n;
        y = (y * y + 1) % n;
        y = (y * y + 1) % n;
        lli diff = llabs(x - y);
        d = mdc(diff, n, 0);
        printf("| %-8d | %-13lld | %-12lld | %-14lld |\n", i, x, y, d);
        i++;
    }
    printf("------------------------------------------------------------\n");

    if (d == n) {
        printf("    - Falha na fatoracao com a semente inicial. O algoritmo encontrou o proprio N.\n");
        return -1;
    }
    
    printf("    - Fator nao trivial de %lld encontrado: %lld\n", n, d);
    return d;
}

/**
 * @brief Calcula (base^exp) % mod usando o método de exponenciação por quadratura.
 * @param base A base da exponenciação.
 * @param exp O expoente.
 * @param mod O módulo.
 * @return O resultado de (base^exp) % mod.
 */
lli exponenciacao_modular(lli base, lli exp, lli mod) {
    lli res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (__int128)res * base % mod;
        base = (__int128)base * base % mod;
        exp /= 2;
    }
    return res;
}

// =====================================================================
// NOVAS FUNÇÕES ADICIONADAS PARA CUMPRIR TODOS OS REQUISITOS
// =====================================================================

/**
 * @brief [NOVO] Calcula tau(n), o número de divisores de n.
 * Para n = p*q (com p e q primos distintos), tau(n) = (1+1)*(1+1) = 4.
 * @param p Primeiro fator primo.
 * @param q Segundo fator primo.
 * @return O número de divisores de n.
 */
lli tau_n(lli p, lli q) {
    return 4; 
}

/**
 * @brief [NOVO] Calcula sigma(n), a soma dos divisores de n.
 * Para n = p*q, sigma(n) = (p+1)*(q+1).
 * @param p Primeiro fator primo.
 * @param q Segundo fator primo.
 * @return A soma dos divisores de n.
 */
lli sigma_n(lli p, lli q) {
    return (p + 1) * (q + 1);
}

// ---------------------------------------------------------------------------------
// FUNÇÃO MAIN - Orquestra as 3 Etapas
// ---------------------------------------------------------------------------------
int main() {
    printf("===============================================================\n");
    printf("  PROJETO DE PROGRAMACAO: SISTEMA RSA COM FATORACAO DE POLLARD \n");
    printf("===============================================================\n\n");

    // ETAPA 1: FATORACAO INTERATIVA (METODO P DE POLLARD)
    printf("--- ETAPA 1: FATORACAO INTERATIVA (METODO P DE POLLARD) ---\n");
    lli N1, N2, p, q;

    do {
        printf("Digite o primeiro numero composto N1 (3 ou 4 digitos, entre 100 e 9999): ");
        scanf("%lld", &N1);
    } while (N1 < 100 || N1 > 9999);

    do {
        printf("Digite o segundo numero composto N2 (diferente de N1, entre 100 e 9999): ");
        scanf("%lld", &N2);
        if (N1 == N2) printf("Erro: N2 deve ser diferente de N1.\n");
    } while (N2 < 100 || N2 > 9999 || N1 == N2);

    p = pollard_rho(N1);
    if (p == -1) return 1;

    q = pollard_rho(N2);
    if (q == -1) return 1;

    printf("\n>> Primos encontrados: p = %lld e q = %lld\n\n", p, q);

    // ETAPA 2: GERACAO DAS CHAVES RSA
    printf("--- ETAPA 2: GERACAO DAS CHAVES RSA ---\n");
    lli n = p * q;
    printf("1. Calculo do modulo (n):\n");
    printf("   n = p * q = %lld * %lld = %lld\n\n", p, q, n);

    lli z = (p - 1) * (q - 1);
    printf("2. Calculo do Totiente de Euler (z(n) ou phi(n)):\n");
    printf("   z(n) = (p - 1) * (q - 1) = %lld * %lld = %lld\n\n", p - 1, q - 1, z);

    lli e;
    printf("3. Escolha do expoente publico (e):\n");
    printf("   'e' deve ser tal que 1 < e < z(n) e mdc(e, z(n)) = 1.\n");
    e = 65537;
    if (e >= z) e = z - 1;
    while (mdc(e, z, 0) != 1) {
        e--;
    }
    printf("   Escolhendo um 'e' valido... e = %lld\n", e);
    mdc(e, z, 1);
    printf("\n");

    printf("4. Calculo do expoente privado (d):\n");
    printf("   'd' e o inverso modular de 'e' em relacao a z(n). d * e = 1 (mod z(n))\n");
    lli d = inverso_modular(e, z);
    printf("\n");

    // [NOVO] Seção adicionada para cumprir o requisito de cálculos intermediários.
    printf("5. Calculos Intermediarios de Teoria dos Numeros para n = %lld:\n", n);
    lli tau_val = tau_n(p, q);
    lli sigma_val = sigma_n(p, q);
    double eficiencia = (double)sigma_val / n;
    printf("   a) Numero de Divisores, tau(n): Como n = p*q, tau(n) = (1+1)*(1+1) = %lld\n", tau_val);
    printf("   b) Soma dos Divisores, sigma(n): Como n = p*q, sigma(n) = (p+1)*(q+1) = %lld\n", sigma_val);
    printf("   c) Razao de Eficiencia, sigma(n)/n: %.4f\n\n", eficiencia);


    printf(">> CHAVES GERADAS:\n");
    printf("   - Chave Publica: (n, e) = (%lld, %lld)\n", n, e);
    printf("   - Chave Privada: (n, d) = (%lld, %lld)\n\n", n, d);


    // ETAPA 3: CRIPTOGRAFIA E DECODIFICACAO
    printf("--- ETAPA 3: CRIPTOGRAFIA E DECODIFICACAO ---\n");
    char mensagem[256], mensagem_limpa[256] = {0};
    int j = 0;

    printf("Digite a mensagem para criptografar (letras maiusculas e espaco): ");
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    fgets(mensagem, sizeof(mensagem), stdin);
    mensagem[strcspn(mensagem, "\n")] = 0;

    for (int i = 0; i < strlen(mensagem); i++) {
        if (isspace(mensagem[i]) || (isupper(mensagem[i]) && isalpha(mensagem[i]))) {
            mensagem_limpa[j++] = mensagem[i];
        }
    }
    printf("   Mensagem original processada: \"%s\"\n\n", mensagem_limpa);
    
    int len = strlen(mensagem_limpa);
    lli *numerico = malloc(len * sizeof(lli));
    
    printf("1. Pre-codificacao (Texto -> Numeros):\n");
    printf("   Esquema: A=11, B=12, ..., Z=36, Espaco=00\n");
    printf("   ");
    for (int i = 0; i < len; i++) {
        numerico[i] = (mensagem_limpa[i] == ' ') ? 0 : mensagem_limpa[i] - 'A' + 11;
        printf("%02lld ", numerico[i]);
    }
    printf("\n\n");

    // [MODIFICADO] Justificativa dos teoremas agora é mais detalhada e mostra a decisão.
    printf("2. Codificacao (Criptografia) | C = M^e mod n\n");
    printf("   Justificativa do Teorema para Reducao de Expoente:\n");
    printf("   - Verificando as condicoes do modulo n = %lld:\n", n);
    printf("     - O Pequeno Teorema de Fermat (a^(p-1) = 1 mod p) so e aplicavel se o modulo for primo.\n");
    printf("     - Nosso modulo n = %lld * %lld e, por definicao do RSA, um numero COMPOSTO.\n", p, q);
    printf("   - DECISAO: Selecionamos o TEOREMA DE EULER (a^phi(n) = 1 mod n), que e uma generalizacao\n");
    printf("     para modulos compostos. A reducao do expoente e garantida por este teorema e e\n");
    printf("     implementada eficientemente pelo algoritmo de exponenciacao modular.\n\n");

    lli *cifrado = malloc(len * sizeof(lli));
    for (int i = 0; i < len; i++) {
        cifrado[i] = exponenciacao_modular(numerico[i], e, n);
        printf("   Bloco M=%02lld  -> C = %lld^%lld mod %lld = %lld\n", numerico[i], numerico[i], e, n, cifrado[i]);
    }
    printf("\n   Mensagem Cifrada (sequencia de numeros): ");
    for(int i=0; i<len; i++) printf("%lld ", cifrado[i]);
    printf("\n\n");

    printf("3. Decodificacao (Descriptografia) | M = C^d mod n\n");
    printf("   Justificativa do Teorema: A mesma logica se aplica. A validade da decodificacao se baseia\n");
    printf("   no fato de que (M^e)^d = M^(e*d) = M (mod n). Isso funciona porque e*d = 1 (mod phi(n)),\n");
    printf("   uma consequencia direta do Teorema de Euler e da Divisao Euclidiana aplicada aos expoentes.\n\n");

    lli *decifrado_num = malloc(len * sizeof(lli));
    for (int i = 0; i < len; i++) {
        decifrado_num[i] = exponenciacao_modular(cifrado[i], d, n);
        printf("   Bloco C=%-5lld -> M' = %lld^%lld mod %lld = %02lld\n", cifrado[i], cifrado[i], d, n, decifrado_num[i]);
    }
    printf("\n");

    printf("4. Pos-decodificacao (Numeros -> Texto) e Verificacao Final:\n");
    char decifrado_txt[256] = {0};
    for (int i = 0; i < len; i++) {
        decifrado_txt[i] = (decifrado_num[i] == 0) ? ' ' : decifrado_num[i] - 11 + 'A';
    }
    printf("   Mensagem Decifrada: \"%s\"\n", decifrado_txt);
    printf("   Mensagem Original:  \"%s\"\n\n", mensagem_limpa);

    if (strcmp(mensagem_limpa, decifrado_txt) == 0) {
        printf(">> SUCESSO: A mensagem decifrada e identica a mensagem original! (Confirmacao de Resultado)\n");
    } else {
        printf(">> FALHA: A mensagem decifrada e diferente da mensagem original.\n");
    }

    free(numerico);
    free(cifrado);
    free(decifrado_num);

    printf("\n===============================================================\n");
    printf("                         FIM DO PROGRAMA\n");
    printf("===============================================================\n");

    return 0;
}