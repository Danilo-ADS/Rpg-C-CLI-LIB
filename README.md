# Caçadores de GOT

**Caçadores de GOT** é um jogo de combate interativo desenvolvido utilizando a **CLI-lib** para interação com o terminal. O jogador enfrenta inimigos e pode realizar ações como atacar, esquivar e melhorar suas habilidades. A cada turno, o jogador escolhe suas ações e o sistema do jogo exibe o estado atual da batalha, incluindo a vida do jogador e do inimigo.

---

## 🎮 Regras do Jogo

- **Atacar (a):** O jogador pode escolher atacar o inimigo.  
- **Esquivar (e):** O jogador pode tentar esquivar de um ataque inimigo.  
- **Melhorias:** Após cada combate, o jogador pode escolher melhorias para suas habilidades (como ataque ou esquiva).  

🎯 O objetivo do jogo é derrotar inimigos, melhorar as habilidades do jogador e alcançar a maior pontuação possível.

---

## 👥 Membros da Equipe

- **Danilo Novaes** - [@Danilo-ADS](https://github.com/Danilo-ADS)

---

## 📂 Repositório

O código-fonte da biblioteca está disponível no GitHub:  
🔗 [https://github.com/tgfb/cli-lib](https://github.com/tgfb/cli-lib)

---

## 📘 Informações Acadêmicas

- **Disciplina:** Programação Imperativa e Funcional - 2025.1  
- **Instituição:** CESAR School

---

## 📦 Sobre a Biblioteca

A **CLI-lib** é uma biblioteca modular que visa simplificar a criação de interfaces de linha de comando em C. Ela oferece funcionalidades como:

- **Parsing de Argumentos:** Interpretação e processamento de argumentos passados via terminal.  
- **Validação de Entrada:** Garante que os dados inseridos pelo usuário sejam válidos.  
- **Execução de Comandos:** Estrutura organizada para execução de comandos interativos.

---

## 🚀 Como Usar a CLI-lib

1. Baixe o repositório da biblioteca no GitHub.  
2. Adicione os arquivos da biblioteca ao seu projeto.  
3. Inclua o cabeçalho da CLI-lib no seu código:

    ```c
    #include "cli-lib.h"
    ```

4. Compile o código. Se necessário, adicione a pasta da biblioteca ao seu caminho de includes.

---

## 🛠️ Instruções de Compilação

Para compilar o projeto, execute o seguinte comando no terminal:

```bash
gcc src/main.c src/keyboard.c src/screen.c src/timer.c -Iinclude -o jogo.exe
```
### 🔍 Explicação

- `src/main.c src/keyboard.c src/screen.c src/timer.c`: Arquivos-fonte do projeto  
- `-Iinclude`: Adiciona a pasta `include` ao caminho de cabeçalhos  
- `-o jogo.exe`: Define o nome do executável como `jogo.exe`


