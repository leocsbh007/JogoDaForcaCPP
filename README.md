# Jogo da Forca em C++

Este projeto implementa um **Jogo da Forca** simples em C++, permitindo que o usuário jogue, adivinhe palavras e adicione novas palavras ao banco de dados.

## 📋 Funcionalidades

- Exibe a interface do jogo com o cabeçalho.
- Sorteia uma palavra aleatória a partir de um arquivo de texto.
- Permite que o jogador adivinhe letras.
- Indica acertos e erros durante o jogo.
- Gerencia a quantidade de erros permitidos (máximo de 5).
- Exibe a palavra oculta com as letras já adivinhadas.
- Permite adicionar novas palavras ao banco de palavras.

## 🛠️ Requisitos

- **Compilador C++** compatível com o padrão C++11 ou superior.
- **Arquivo `palavras.txt`**:
  - Deve conter a quantidade de palavras na primeira linha.
  - Cada linha subsequente deve ter uma palavra em letras maiúsculas.

Exemplo de arquivo `palavras.txt`:


## 🚀 Como usar

1. **Compile o programa**:
   ```bash
   g++ -o jogo_forca jogo_forca.cpp
    ./jogo_forca
## Durante o jogo:

- Insira letras para adivinhar.
- Após acertar ou perder, escolha se deseja adicionar uma nova palavra ao banco.

## 🧩 Principais Funções

- **`bLetraExiste`**: Verifica se a letra adivinhada existe na palavra sorteada.
- **`bNaoAcertou`**: Determina se o jogador ainda não completou a palavra.
- **`bNaoEnforcou`**: Verifica se o jogador ainda tem tentativas disponíveis.
- **`vImprimeCabecalho`**: Exibe o cabeçalho do jogo.
- **`vPrintErrors`**: Exibe os erros cometidos pelo jogador.
- **`vPrintWord`**: Mostra a palavra com as letras já adivinhadas e os espaços restantes.
- **`vKick`**: Gerencia os chutes do jogador, verificando acertos e registrando erros.
- **`vecLeArquivo`**: Lê o banco de palavras a partir do arquivo `palavras.txt`.
- **`vSorteiaPalavra`**: Escolhe uma palavra aleatória do banco.
- **`vSalvaArquivo`**: Salva uma nova palavra no banco de palavras.
- **`vAdicionaPalavra`**: Permite que o jogador adicione novas palavras ao banco.

## 📂 Estrutura do Projeto

- **`jogo_forca.cpp`**: Arquivo principal com a implementação do jogo.
- **`palavras.txt`**: Banco de palavras utilizado pelo programa.

## 🤝 Contribuições

Contribuições são bem-vindas! Sinta-se à vontade para criar issues e pull requests no repositório.

## 🔗 Siga-me nas redes sociais:

- [Instagram: @embarcado-tech](https://instagram.com/embarcado-tech)
- [TikTok: @leocsbh007](https://tiktok.com/@leocsbh007)
- [GitHub: leocsbh007](https://github.com/leocsbh007)


