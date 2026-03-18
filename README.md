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

Você pode executar o algoritmo em três cenários diferentes para comparar o desempenho:

### 1. Versão Sequencial (Single Thread)

Roda o binário compilado sem as diretivas de paralelismo.

```bash
./gauss_elimination
```

### 2. Versão Paralela (Carga Total)

Usa o OpenMP com o comportamento padrão (utiliza todos os núcleos lógicos disponíveis no seu Arch Linux).

```bash
./gauss_elimination_openmp
```

### 3. Versão Paralela (Limitada)

Define manualmente a quantidade de threads para testar a escalabilidade.

```bash
export OMP_NUM_THREADS=4
./gauss_elimination_openmp
```

 ## Estrutura
* `gauss-elimination.c`: Core do algoritmo (Eliminação e Substituição Regressiva).
* `tests.c`: Suite de testes unitários.
* `Makefile`: Scripts de compilação automatizada.

