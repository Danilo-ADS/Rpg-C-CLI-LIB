#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int ataque = 3;
int esquiva = 13;
int vida_jogador = 10;

typedef struct
{
    const char *nome;
    int vida;
    int dano;
    int frequencia;
    int contador;
} Inimigo;

int rolar_dados()
{
    return (rand() % 6 + 1) + (rand() % 6 + 1) + (rand() % 6 + 1);
}

void combate()
{
    Inimigo troll = {"Troll", 10, 7, 3, 3};

    int rodada = 1;

    printf("\nVocê encontrou um %s!\n", troll.nome);

    while (vida_jogador > 0 && troll.vida > 0)
    {
        printf("\n--- Rodada %d ---\n", rodada++);
        printf("Sua vida: %d | Vida do %s: %d\n", vida_jogador, troll.nome, troll.vida);
        printf("Escolha: (a) Atacar | (e) Esquivar\n");

        char acao = _getch();
        printf("%c\n", acao);

        int defesa_turno = esquiva;
        if (acao == 'e')
        {
            defesa_turno += 2;
            printf("Você se preparou para esquivar.\n");
        }

        troll.contador--;
        if (troll.contador <= 0)
        {
            int ataque_inimigo = rolar_dados() + troll.dano;
            printf("%s ataca com força total %d contra sua esquiva %d.\n", troll.nome, ataque_inimigo, defesa_turno);
            if (ataque_inimigo > defesa_turno)
            {
                vida_jogador -= troll.dano;
                printf("Você foi atingido! Perdeu %d de vida.\n", troll.dano);
            }
            else
            {
                printf("Você esquivou do ataque!\n");
            }
            troll.contador = troll.frequencia;
        }
        else
        {
            printf("%s se prepara para atacar...\n", troll.nome);
        }

        if (acao == 'a')
        {
            int ataque_jogador = rolar_dados() + ataque;
            if (ataque_jogador > 10)
            {
                troll.vida -= ataque;
                printf("Você acertou! Causou %d de dano.\n", ataque);
            }
            else
            {
                printf("Você errou o ataque.\n");
            }
        }

        if (vida_jogador <= 0)
        {
            printf("\nVocê foi derrotado...\n");
            return;
        }
        if (troll.vida <= 0)
        {
            printf("\nVocê venceu o %s!\n", troll.nome);
            return;
        }
    }
}

int main()
{
    srand(time(NULL));
    printf("=== Demonstração de Combate ===\n");
    combate();
    return 0;
}
