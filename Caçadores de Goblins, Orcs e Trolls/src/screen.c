#include <stdio.h>
#include "screen.h"

void exibir_combate(const char *jogador, const char *inimigo, int vida_jogador, int vida_inimigo)
{
    printf("\n  Combate %s contra %s (Vida jogador: %d | Vida do inimigo: %d)\n", jogador, inimigo, vida_jogador, vida_inimigo);
}

void exibir_ataque(int ataque_jogador, int defesa_inimigo)
{
    printf(" Você ataca com total %d contra defesa %d\n", ataque_jogador, defesa_inimigo);
}

void exibir_resultado_combate(int vida_jogador, const char *inimigo)
{
    if (vida_jogador <= 0)
    {
        printf(" Você foi derrotado no combate com %s...\n", inimigo);
    }
    else
    {
        printf(" Você venceu o combate contra %s!\n", inimigo);
    }
}
