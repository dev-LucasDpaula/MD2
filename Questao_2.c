#include <stdio.h>

int main() {

    int numero_itens;

    scanf("%d", &numero_itens);

    int vetor[numero_itens];

    for(int i = 0; i < (numero_itens + 1); i++){
        scanf("%d", &vetor[i]);
    }

    boolean ativas = false;
    int ano = 0;

    while (ativas == false && ano < 50){
        
        ano++;
        ativas = true;

        for(int i = 0; i < (numero_itens + 1); i++){
            if (ano % vetor[i] != 0){
                ativas = false;
            }
        }

    }

}

Co-authored-by: dev-LucasDpaula <dev-LucasDpaula@users.noreply.github.com>