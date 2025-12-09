#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função auxiliar para retornar o maior de dois números
int max(int a, int b) {
    return (a > b) ? a : b;
}

// ---------------------------------------------------------
// ALGORITMO 1: Força Bruta (Recursivo)
// Complexidade: O(2^n) - Cresce exponencialmente
// ---------------------------------------------------------
int mochilaForcaBruta(int W, int wt[], int val[], int n) {
    // Caso base: sem itens ou capacidade zero
    if (n == 0 || W == 0)
        return 0;

    // Se o peso do item atual é maior que a capacidade, não podemos incluí-lo
    if (wt[n - 1] > W)
        return mochilaForcaBruta(W, wt, val, n - 1);

    // Caso contrário, retornamos o máximo entre:
    // 1. (Incluir o item): valor do item + valor do restante com capacidade reduzida
    // 2. (Excluir o item): valor do restante com a mesma capacidade
    else
        return max(
            val[n - 1] + mochilaForcaBruta(W - wt[n - 1], wt, val, n - 1),
            mochilaForcaBruta(W, wt, val, n - 1)
        );
}

// ---------------------------------------------------------
// ALGORITMO 2: Programação Dinâmica (Tabulação)
// Complexidade: O(n * W) - Pseudo-polinomial
// ---------------------------------------------------------
int mochilaDinamica(int W, int wt[], int val[], int n) {
    int i, w;
    
    // Alocação dinâmica da matriz (Tabela DP) para suportar valores grandes
    // Estamos criando uma tabela K[n+1][W+1]
    int **K = (int **)malloc((n + 1) * sizeof(int *));
    for (i = 0; i <= n; i++)
        K[i] = (int *)malloc((W + 1) * sizeof(int));

    // Preenchendo a tabela de forma iterativa (Bottom-up)
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    int resultado = K[n][W]; // O resultado está na última célula

    // Liberar memória da tabela (boa prática em C)
    for (i = 0; i <= n; i++) free(K[i]);
    free(K);

    return resultado;
}

// ---------------------------------------------------------
// Função para gerar testes e medir tempo
// ---------------------------------------------------------
void executarTeste(int n, int W) {
    // Aloca arrays para pesos e valores
    int *val = (int *)malloc(n * sizeof(int));
    int *wt = (int *)malloc(n * sizeof(int));

    // Gera dados aleatórios para o teste
    // Valores entre 10 e 100, Pesos entre 1 e 30
    for(int i=0; i<n; i++) {
        val[i] = (rand() % 90) + 10; 
        wt[i]  = (rand() % 30) + 1;
    }

    clock_t inicio, fim;
    double tempo_gasto;
    int res;

    // --- Teste Força Bruta ---
    // Apenas rodamos força bruta se N for pequeno (N < 35) para não travar o PC
    if (n <= 32) {
        inicio = clock();
        res = mochilaForcaBruta(W, wt, val, n);
        fim = clock();
        tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        
        // Formato CSV: Algoritmo, N, Capacidade, Tempo(s), ResultadoMaximo
        printf("Bruta,%d,%d,%.6f,%d\n", n, W, tempo_gasto, res);
    }

    // --- Teste Dinâmica ---
    inicio = clock();
    res = mochilaDinamica(W, wt, val, n);
    fim = clock();
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    
    printf("Dinamica,%d,%d,%.6f,%d\n", n, W, tempo_gasto, res);

    free(val);
    free(wt);
}

int main() {
    srand(time(NULL)); 
    printf("Algoritmo,N_Itens,Capacidade_Mochila,Tempo_Segundos\n");

    // FASE 1: Pequena escala (Comparação Bruta vs Dinâmica)
    // De 10 até 28 itens
    int capacidadePequena = 50;
    for (int n = 10; n <= 28; n += 2) {
        executarTeste(n, capacidadePequena);
    }

    // FASE 2: Grande escala (Apenas Dinâmica)
    // Vamos usar potências de 2 para chegar até 2^20 (aprox 1 milhão)
    // Capacidade fixa em 100 para economizar RAM
    int capacidadeFixa = 100; 
    
    // Começa em 2^5 (32) e vai até 2^20 (1.048.576)
    // Multiplicando n por 2 a cada loop (crescimento exponencial do teste)
    for (int n = 32; n <= 1048576; n *= 2) {
        executarTeste(n, capacidadeFixa);
    }

    return 0;
}