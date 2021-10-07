# Multiplicação matriz-vetor

## Dados
  - matriz = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
  - vetor = [2, 4, 6]
  - m = 3 quantidade de linha
  - n = 3 quantidade de coluna
  - thread_count = 3 quantidade de thread que vai usar

## Explicação
  - Em cada linha da matriz, multiplica um por um entre o elemento do vetor e o elemento da linha. Ao final soma os resultados obtidos da multiplicação
  - 1 * 2 + 2 * 4 + 3 * 6 = 28
  - 4 * 2 + 5 * 4 + 6 * 6 = 64
  - 7 * 2 + 8 * 4 + 9 * 6 = 100
  - vetor final: 28, 64, 100

## Compilar e rodar
  - gcc -g -Wall -o main main.c -lpthread
  - ./main
