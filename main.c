#include <stdio.h> // biblioteca entrada e saida
#include <string.h> // usar strlen
#include <ctype.h> // usar tolower

#define MAX_ERROS 6 

int main() {
    char palavraSecreta[] = "emanuelle"; 
    char palavraDescoberta[50];
    char letra;
    int i, erros = 0, acertos = 0;
    int tamanho = strlen(palavraSecreta);
    int letrasCertas[50] = {0}; 

    
    for (i = 0; i < tamanho; i++) {
        palavraDescoberta[i] = '_';
    }
    palavraDescoberta[tamanho] = '\0';

    printf("=== JOGO DA FORCA ===\n");

    while (erros < MAX_ERROS && acertos < tamanho) {
        printf("\nPalavra: ");
        for (i = 0; i < tamanho; i++) {
            printf("%c ", palavraDescoberta[i]);
        }

        printf("\nDigite uma letra: ");
        scanf(" %c", &letra);
        letra = tolower(letra); 

        int acertou = 0;
        for (i = 0; i < tamanho; i++) {
            if (palavraSecreta[i] == letra && letrasCertas[i] == 0) {
                palavraDescoberta[i] = letra;
                letrasCertas[i] = 1;
                acertos++;
                acertou = 1;
            }
        }

        if (!acertou) {
            erros++;
            printf("Letra incorreta! Você cometeu %d erro(s).\n", erros);
        }
    }

    if (acertos == tamanho) {
        printf("\nVocê acertou a palavra: %s\n", palavraSecreta);
    } else {
        printf("\nVocê perdeu! A palavra era: %s\n", palavraSecreta);
    }

    return 0;
}
