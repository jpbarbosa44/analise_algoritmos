# Estudo de Complexidade: Problema da Mochila (Knapsack Problem)

Este projeto realiza uma análise comparativa de desempenho entre duas abordagens para o Problema da Mochila 0/1: **Força Bruta** (Recursiva) e **Programação Dinâmica**.

## 🛠️ Pré-requisitos

Antes de rodar, certifique-se de ter instalado:

  * **Compilador C:** GCC (Recomendado: MSYS2/MinGW para Windows).
  * **Python 3.10+**
  * **Bibliotecas Python:**
    ```bash
    pip install pandas matplotlib seaborn scipy
    ```
  * **VS Code** (com extensões C/C++ e Jupyter).

-----

## 🚀 Como Executar

Siga os passos abaixo estritamente para reproduzir os experimentos.

### Passo 1: Compilar e Rodar o Código C

1.  Abra o terminal na pasta do projeto.
2.  Compile o código:
    ```bash
    gcc main.c -o main.exe
    ```
3.  Execute o programa:
    ```bash
    ./main.exe
    ```
    *Ou use o botão "Run" (Play) do VS Code.*

-----

### Passo 2: Extração de Dados (IMPORTANTE ⚠️)

O programa C imprimirá os resultados diretamente no Terminal (Console). **Você precisa salvar esses dados manualmente.**

1.  No terminal, selecione todo o texto gerado, **desde o cabeçalho até a última linha**.
      * O texto começa com: `Algoritmo,N_Itens,Capacidade_Mochila...`
      * E termina com a última linha de dados (ex: `Dinamica,1000,...`).
2.  Copie a seleção (`Ctrl+C`).
3.  Abra (ou crie) o arquivo chamado **`data.csv`** na raiz do projeto.
4.  Cole o conteúdo (`Ctrl+V`) e salve o arquivo.

> **Exemplo de como o arquivo `data.csv` deve ficar:**
>
> ```csv
> Algoritmo,N_Itens,Capacidade_Mochila,Tempo_Segundos,Valor_Maximo
> Bruta,10,1000,0.000000,573
> Dinamica,10,1000,0.000000,573
> ...
> Dinamica,1000,1000,0.145000,14948
> ```

-----

### Passo 3: Análise de Data Science

1.  Abra o arquivo Jupyter Notebook (ex: `analise.ipynb`).
2.  Certifique-se de que o arquivo `data.csv` está salvo na mesma pasta.
3.  Execute todas as células ("Run All").
4.  Os gráficos serão gerados e salvos automaticamente como imagens `.png` na pasta.

-----

## 📊 Estrutura dos Testes

  * **Fase 1 (Pequena Escala):** Compara Força Bruta vs Dinâmica até $N=32$ (onde a força bruta atinge \~30s).
  * **Fase 2 (Larga Escala):** Testa apenas a Dinâmica até $N=1.000$ (ou $2^{20}$ dependendo da configuração) para provar a linearidade $O(N)$.

-----

## 📝 Autor
João Pedro Barbosa e Gabriel H Coetti
Projeto desenvolvido para a disciplina de Análise de Algoritmos.