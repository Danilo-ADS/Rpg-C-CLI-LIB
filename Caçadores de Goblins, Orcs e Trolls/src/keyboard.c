#include <stdio.h>
#include <conio.h>
#include "keyboard.h"

char obter_acao_jogador()
{
    char acao;
    printf("Você quer atacar (a) ou esquivar (e)? ");
    acao = getch();
    return acao;
}

int escolher_melhoria()
{
    char tecla;
    printf("\n--- Escolha uma melhoria ---\n");
    printf("1. +1 Ataque (Atual)\n");
    printf("2. +1 Esquiva (Atual)\n");
    printf("> ");
    tecla = getch();
    printf("%c\n", tecla);

    if (tecla == '1')
        return 1;
    if (tecla == '2')
        return 2;

    return 0;
}