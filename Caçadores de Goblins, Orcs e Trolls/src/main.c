#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "keyboard.h"
#include "screen.h"
#include "timer.h" // Temporizador implementado
#include "conio.h"
#include "string.h"

// Definindo variáveis do jogo
int ataque = 3;
int esquiva = 13;
int vida_jogador = 10;
int vitorias = 0;

// Contadores de inimigos derrotados por tipo
int goblins_derrotados = 0;
int orcs_derrotados = 0;
int trolls_derrotados = 0;

typedef struct
{
    char nome[100];
    int pontos;
} RegistroPontuacao;

typedef struct
{
    const char *nome;
    int dano;
    int frequencia;
    int contador;
    int vida_max;
    int vida;
    int esquiva_base;
    int esquiva; // Adicionado o campo esquiva
    int pontos;  // Pontos ganhos ao derrotar esse inimigo
} Inimigo;

Inimigo goblin = {"Goblin", 3, 1, 1, 4, 4, 10, 10, 50};  // 50 pontos por derrotar um Goblin
Inimigo orc = {"Orc", 5, 1, 1, 6, 6, 10, 10, 100};       // 100 pontos por derrotar um Orc
Inimigo troll = {"Troll", 7, 3, 3, 10, 10, 15, 15, 150}; // 150 pontos por derrotar um Troll

// Declarar a função iniciar_jogo para evitar o warning
void iniciar_jogo();

// Limpa buffer do teclado (evita leitura errada com scanf)
void limpar_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

// Função para rolar dados
int rolar_dados()
{
    int d1 = rand() % 6 + 1;
    int d2 = rand() % 6 + 1;
    int d3 = rand() % 6 + 1;
    int soma = d1 + d2 + d3;
    printf("Dados: %d, %d, %d (Total: %d)\n", d1, d2, d3, soma);
    return soma;
}

// Escolher inimigo com base na rodada
Inimigo *escolher_inimigo(int rodada)
{
    if (rodada <= 2)
        return &goblin;
    if (rodada <= 4)
        return rand() % 2 == 0 ? &goblin : &orc;
    int r = rand() % 3;
    return r == 0 ? &troll : (r == 1 ? &orc : &goblin);
}

// Função de combate
int combate(Inimigo *inimigo, const char *nome)
{
    inimigo->vida = inimigo->vida_max;
    inimigo->contador = inimigo->frequencia;

    int rodada = 1;

    printf("\n  Combate %s contra %s (Vida inimigo: %d)\n", nome, inimigo->nome, inimigo->vida);

    while (vida_jogador > 0 && inimigo->vida > 0)
    {
        inimigo->esquiva = inimigo->esquiva_base;
        printf("\nRodada %d\n", rodada++);
        printf("Sua vida: %d | Vida do %s: %d\n", vida_jogador, inimigo->nome, inimigo->vida);

        int inimigo_ataca = 1; // Permite o ataque do inimigo

        char acao;
        printf("Você quer atacar (a) ou esquivar (e)? ");
        acao = _getch();      // Captura a tecla pressionada imediatamente sem esperar "Enter"
        printf("%c\n", acao); // Apenas para mostrar a escolha

        int defesa_turno = esquiva;
        if (acao == 'e')
        {
            defesa_turno += 2;
            printf(" Você se preparou para esquivar. Esquiva neste turno: %d\n", defesa_turno);
        }

        // Lógica do inimigo conforme o tipo
        if (strcmp(inimigo->nome, "Goblin") == 0)
        {
            if (inimigo->contador % 2 == 1)
            {
                // Goblin ataca
                int ataque_inimigo = rolar_dados() + inimigo->dano;
                printf("O Goblin ataca com total %d vs sua esquiva %d\n", ataque_inimigo, defesa_turno);
                if (ataque_inimigo > defesa_turno)
                {
                    vida_jogador -= inimigo->dano;
                    printf(" O Goblin acertou! Você perdeu %d de vida.\n", inimigo->dano);
                }
                else
                {
                    printf(" Você esquivou do ataque!\n");
                }
            }
            else
            {
                // Goblin esquiva
                printf("O Goblin se esquiva!\n");
                inimigo->esquiva += 1; // Goblin ganha +1 de esquiva ao se esquivar
                printf(" A esquiva do Goblin agora é %d\n", inimigo->esquiva);
            }
            inimigo->contador++;
        }
        else if (strcmp(inimigo->nome, "Orc") == 0)
        {
            if (inimigo->contador % 3 == 0)
            {
                // Orc cansa
                printf("O Orc está cansado e perde 2 de esquiva!\n");
                inimigo->esquiva -= 2;
                if (inimigo->esquiva < 0)
                    inimigo->esquiva = 0;
            }
            else
            {
                // Orc ataca
                int ataque_inimigo = rolar_dados() + inimigo->dano;
                printf("O Orc ataca com total %d vs sua esquiva %d\n", ataque_inimigo, defesa_turno);
                if (ataque_inimigo > defesa_turno)
                {
                    vida_jogador -= inimigo->dano;
                    printf(" O Orc acertou! Você perdeu %d de vida.\n", inimigo->dano);
                }
                else
                {
                    printf(" Você esquivou do ataque!\n");
                }
            }
            inimigo->contador++;
        }
        else if (strcmp(inimigo->nome, "Troll") == 0)
        {
            // Troll se cura 2 de vida
            inimigo->vida += 2;
            if (inimigo->vida > inimigo->vida_max)
                inimigo->vida = inimigo->vida_max;
            printf("O Troll se cura 2 de vida. Vida atual: %d\n", inimigo->vida);

            if (inimigo->contador % 3 == 1)
            {
                // Troll ataca
                int ataque_inimigo = rolar_dados() + inimigo->dano;
                printf("O Troll ataca com total %d vs sua esquiva %d\n", ataque_inimigo, defesa_turno);
                if (ataque_inimigo > defesa_turno)
                {
                    vida_jogador -= inimigo->dano;
                    printf(" O Troll acertou! Você perdeu %d de vida.\n", inimigo->dano);
                }
                else
                {
                    printf(" Você esquivou do ataque!\n");
                }
            }
            else
            {
                printf("O Troll não atacou neste turno.\n");
            }
            inimigo->contador++;
        }

        // Ataque do jogador
        if (acao == 'a')
        {
            int ataque_jogador = rolar_dados() + ataque;
            printf(" Você ataca com total %d contra defesa %d\n", ataque_jogador, inimigo->esquiva);
            if (ataque_jogador > inimigo->esquiva)
            {
                inimigo->vida -= ataque;
                printf(" Ataque bem-sucedido! Vida do %s agora: %d\n", inimigo->nome, inimigo->vida);
            }
            else
            {
                printf(" Você errou o ataque.\n");
            }
        }

        if (vida_jogador <= 0)
        {
            printf(" Você foi derrotado...\n");
            return 0;
        }

        if (inimigo->vida <= 0)
        {
            printf(" %s foi derrotado!\n", inimigo->nome);
            return 1;
        }
    }

    return 0;
}

// Função para calcular a pontuação
int calcular_pontuacao()
{
    int pontuacao = vitorias * 100; // 100 pontos por vitória
    pontuacao += goblins_derrotados * goblin.pontos;
    pontuacao += orcs_derrotados * orc.pontos;
    pontuacao += trolls_derrotados * troll.pontos;
    return pontuacao;
}

// Função para exibir as pontuações dos jogadores
void exibir_pontuacoes()
{
    FILE *file = fopen("pontuacoes.txt", "r");
    if (file == NULL)
    {
        printf("Nenhuma pontuação salva. Comece o jogo!\n");
        return;
    }

    RegistroPontuacao registros[100];
    int count = 0;

    while (fscanf(file, "%s %d", registros[count].nome, &registros[count].pontos) != EOF && count < 100)
    {
        count++;
    }

    fclose(file);

    // Ordenar do maior para o menor (bubble sort simples)
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (registros[j].pontos > registros[i].pontos)
            {
                RegistroPontuacao temp = registros[i];
                registros[i] = registros[j];
                registros[j] = temp;
            }
        }
    }

    // Exibir pontuações ordenadas
    printf("\n--- Ranking de Pontuações ---\n");
    for (int i = 0; i < count; i++)
    {
        printf("%dº %s: %d pontos\n", i + 1, registros[i].nome, registros[i].pontos);
    }
}

// Função para salvar a pontuação do jogador
void salvar_pontuacao(const char *nome, int pontuacao)
{
    FILE *file = fopen("pontuacoes.txt", "a"); // Abre o arquivo para adicionar ao final
    if (file == NULL)
    {
        printf("Erro ao salvar a pontuação! Não foi possível abrir o arquivo.\n");
        return;
    }

    fprintf(file, "%s %d\n", nome, pontuacao); // Escreve a pontuação no arquivo
    fclose(file);                              // Fecha o arquivo após escrever
    printf("Pontuação de %s salva com sucesso! (%d pontos)\n", nome, pontuacao);
}

// Função de melhoria
void melhorar()
{
    printf("\nEscolha uma melhoria:\n");
    printf("1. +1 Ataque (Atual: %d)\n", ataque);
    printf("2. +1 Esquiva (Atual: %d)\n", esquiva);
    char escolha = _getch(); // Captura a tecla sem precisar de "Enter"
    if (escolha == '1')
    {
        ataque++;
        printf("Ataque aumentado para %d!\n", ataque);
    }
    else if (escolha == '2')
    {
        esquiva++;
        printf("Esquiva aumentada para %d!\n", esquiva);
    }
    else
    {
        printf("Opção inválida!\n");
    }
}

// Função para exibir o menu principal
void exibir_menu()
{

    while (1)
    {
        printf("\n---- MENU ----\n");
        printf("1. Ver pontuação dos outros jogadores\n");
        printf("2. Começar o jogo\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        char opcao = _getch();

        switch (opcao)
        {
        case '1':
            exibir_pontuacoes();
            break;
        case '2':
            iniciar_jogo();
            break;
        case '3':
            printf("Saindo... Até logo!\n");
            exit(0);
        default:
            printf("Opção inválida! Tente novamente.\n");
        }
    }
}

// Função para iniciar o jogo
void iniciar_jogo()
{
    while (1)
    {
        srand(time(NULL));
        ataque = 3;
        esquiva = 13;
        vida_jogador = 10;
        vitorias = 0; // Inicializa as vitórias antes de cada novo jogo

        printf(" Bem-vindo ao circuito de combates!\n");

        const char *nomes[] = {"Fácil", "Razoável", "Difícil", "Perigoso", "Insano", "Final"};
        const int total = sizeof(nomes) / sizeof(nomes[0]);
        int derrotados = 0;

        iniciar_temporizador();
        int venceu_jogo = 1;

        for (int i = 0; i < total; i++)
        {
            Inimigo *inimigo = escolher_inimigo(i + 1);
            int venceu = combate(inimigo, nomes[i]);

            if (!venceu)
            {
                printf("  Fim do jogo. Você foi vencido no combate %s.\n", nomes[i]);
                venceu_jogo = 0;
                break;
            }

            // Atualiza os contadores de inimigos derrotados
            if (inimigo == &goblin)
                goblins_derrotados++;
            else if (inimigo == &orc)
                orcs_derrotados++;
            else if (inimigo == &troll)
                trolls_derrotados++;

            vida_jogador = 10; // Restaura a vida após cada combate
            printf(" Vida restaurada para %d!\n", vida_jogador);

            vitorias++; // Incrementa a quantidade de vitórias

            // Verifica se já passou de 2 vitórias e chama a função de melhoria
            if (vitorias % 2 == 0)
            {
                printf("Você tem %d vitórias! Escolha uma melhoria:\n", vitorias);
                melhorar(); // Chama a função para melhorar os atributos
            }

            if (i < total - 1)
            {
                printf(" Deseja continuar para o próximo desafio? (s/n): ");
                char continuar = _getch();
                printf("\n");

                if (continuar != 's' && continuar != 'S')
                {
                    printf(" Você escolheu encerrar o jogo.\n");
                    venceu_jogo = 0;
                    break;
                }
            }
        }

        double tempo_total = parar_temporizador();
        printf("\n Tempo total de jogo: %.2f segundos\n", tempo_total);

        printf("\n Inimigos derrotados:\n");
        printf(" Goblins: %d\n", goblins_derrotados);
        printf(" Orcs: %d\n", orcs_derrotados);
        printf(" Trolls: %d\n", trolls_derrotados);

        int pontuacao = calcular_pontuacao();
        printf("Sua pontuação total: %d\n", pontuacao);

        // Salvar a pontuação do jogador
        char nome_jogador[50]; // Tamanho suficiente para a maioria dos nomes

        printf("Digite seu nome: ");
        fgets(nome_jogador, sizeof(nome_jogador), stdin);

        // Remove o '\n' do final, se existir
        nome_jogador[strcspn(nome_jogador, "\n")] = '\0';

        salvar_pontuacao(nome_jogador, pontuacao);

        if (venceu_jogo && derrotados == total)
        {
            printf(" Parabéns! Você venceu todos os combates!\n");
        }
        else
        {
            printf(" Infelizmente, você foi derrotado ou saiu antes do final.\n");
        }

        printf("\n Deseja jogar novamente? (s/n): ");
        char repetir = _getch();
        printf("\n");
        if (repetir != 's' && repetir != 'S')
        {
            printf(" Obrigado por jogar! Até a próxima!\n");
            break;
        }

        printf("\nReiniciando o jogo...\n\n");
    }
}

// Função main
int main()
{
    exibir_menu();
    return 0;
}
