Caçadores de GOT
Caçadores de GOT é um jogo de combate interativo desenvolvido utilizando a CLI-lib para interação com o terminal. O jogador enfrenta inimigos e pode realizar ações como atacar, esquivar e melhorar suas habilidades. A cada turno, o jogador escolhe suas ações e o sistema do jogo exibe o estado atual da batalha, incluindo a vida do jogador e do inimigo.

🎮 Regras do Jogo
Atacar (a): O jogador pode escolher atacar o inimigo.

Esquivar (e): O jogador pode tentar esquivar de um ataque inimigo.

Melhorias: Após cada combate, o jogador pode escolher melhorias para suas habilidades (como ataque ou esquiva).

O objetivo do jogo é derrotar inimigos, melhorar as habilidades do jogador e alcançar a maior pontuação possível.

👥 Membros da Equipe
Danilo Novaes - @Danilo-ADS

📂 Repositório
O código-fonte da biblioteca está disponível no GitHub:

🔗 https://github.com/tgfb/cli-lib

📘 Informações Acadêmicas
Disciplina: Programação Imperativa e Funcional - 2025.1

Instituição: CESAR School

📦 Sobre a Biblioteca
A CLI-lib é uma biblioteca modular que visa simplificar a criação de interfaces de linha de comando em C. Ela oferece funcionalidades como:

Parsing de Argumentos: Capacidade de interpretar e processar argumentos fornecidos ao programa através da linha de comando.

Validação de Entrada: Facilita a validação de dados inseridos pelo usuário para garantir que sejam corretos e coerentes.

Execução de Comandos: Fornece uma estrutura organizada para o lançamento e execução de comandos com interação no terminal.

🚀 Como Usar a CLI-lib
Baixe o repositório no GitHub e adicione os arquivos da biblioteca ao seu projeto.

Inclua o cabeçalho da CLI-lib no seu código:

c
Copiar
Editar
#include "cli-lib.h"
Compile e execute o código. Se necessário, adicione a pasta da biblioteca ao seu diretório de includes.

🛠️ Instruções de Compilação
Para compilar o projeto, utilize o comando abaixo no terminal (dentro da pasta raiz do projeto):

gcc src/main.c src/keyboard.c src/screen.c src/timer.c -Iinclude -o jogo.exe
Explicação:
src/main.c src/keyboard.c src/screen.c src/timer.c: Arquivos fonte do projeto.

-Iinclude: Adiciona a pasta include ao caminho de busca de cabeçalhos.

-o jogo.exe: Define o nome do executável de saída como jogo.exe.

Certifique-se de que a biblioteca CLI-lib esteja corretamente copiada para a estrutura do seu projeto e seus arquivos .c e .h estejam sendo incluídos corretamente.
