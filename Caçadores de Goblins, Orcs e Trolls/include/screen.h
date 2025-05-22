#ifndef SCREEN_H
#define SCREEN_H

void exibir_combate(const char *jogador, const char *inimigo, int vida_jogador, int vida_inimigo);

void exibir_ataque(int ataque_jogador, int defesa_inimigo);

void exibir_resultado_combate(int vida_jogador, const char *inimigo);

#endif
