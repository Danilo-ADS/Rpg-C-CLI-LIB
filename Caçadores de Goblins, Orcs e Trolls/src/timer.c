#include <stdio.h>
#include <time.h>
#include "timer.h"

static clock_t tempo_inicio;

void iniciar_temporizador()
{
    tempo_inicio = clock();
}

double parar_temporizador()
{
    clock_t tempo_fim = clock();
    double tempo_decorrido = (double)(tempo_fim - tempo_inicio) / CLOCKS_PER_SEC;
    return tempo_decorrido;
}

double obter_tempo_decorrido()
{
    clock_t tempo_atual = clock();
    double tempo_decorrido = (double)(tempo_atual - tempo_inicio) / CLOCKS_PER_SEC;
    return tempo_decorrido;
}
