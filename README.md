# Gaussian Elimination with OpenMP

Implementação do algoritmo de Eliminação de Gauss para resolução de sistemas lineares em **C**, utilizando indexação de matriz 1D e paralelismo com **OpenMP**.

## Funcionalidades
* **Indexação 1D:** Mapeamento $(row \times cols + col)$ para maior eficiência de cache e memória contígua.
* **Versão Sequencial:** Implementação padrão para comparação de baseline.
* **Versão Paralela:** Escalonamento de linhas otimizado com diretivas OpenMP.
* **Unit Testing:** Suite de testes integrada com `assert.h` para validar a precisão do solver.

## Pré-requisitos (Arch Linux)

```bash
sudo pacman -S base-devel openmp clang
```

## Como Compilar

O projeto utiliza o `Makefile` para gerar binários distintos:

* **Versão Sequencial:**
    ```bash
    make gauss_elimination
    ```
* **Versão Paralela (OpenMP):**
    ```bash
    make gauss_elimination_openmp
    ```
* **Executar Testes Unitários:**
    ```bash
    make test
    ```

## Execução

O programa recebe o tamanho da matriz quadrada ($n$) diretamente como argumento de linha de comando. A matriz é gerada aleatoriamente.

### Regra de Exibição
* **$n <= 5$**: O programa imprime a matriz original, a matriz triangular e o vetor solução $x$.
* **$n \gt 5$**: Apenas o status da execução e os tempos são exibidos para evitar poluição no terminal.

### Cenários de Teste

#### 1. Versão Sequencial (Single Thread)

```bash
./gauss_elimination 100
```

#### 2. Versão Paralela (Carga Total)

Usa todos os cores disponíveis no sistema por padrão.

```bash
./gauss_elimination_openmp 100
```

#### 3. Versão Paralela (Limitada)

Define manualmente o número de threads para testes de escalabilidade.

```bash
export OMP_NUM_THREADS=4
./gauss_elimination_openmp 100
```
