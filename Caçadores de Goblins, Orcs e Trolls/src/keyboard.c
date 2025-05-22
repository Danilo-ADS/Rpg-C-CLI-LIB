#include <stdio.h>
#include <conio.h> // Usamos conio.h para acessar a função getch()
#include "keyboard.h"

char obter_acao_jogador()
{
    char acao;
    printf("Você quer atacar (a) ou esquivar (e)? ");
    acao = getch(); // Captura a tecla pressionada sem precisar pressionar Enter
    return acao;
}

int escolher_melhoria()
{
    char tecla;
    printf("\n--- Escolha uma melhoria ---\n");
    printf("1. +1 Ataque (Atual)\n");
    printf("2. +1 Esquiva (Atual)\n");
    printf("> ");
    tecla = getch(); // Captura a tecla sem precisar de Enter
    printf("%c\n", tecla); // Mostra a tecla pressionada (opcional)

    // Converte o caractere para número inteiro
    if (tecla == '1') return 1;
    if (tecla == '2') return 2;

    // Valor inválido, retorna 0 como padrão
    return 0;
}