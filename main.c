#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *numbers_create(int size); // aloca os espaços para um tamanho fixo
void numbers_read(int *numbers, int size); // ler todos os valores para os espaços
float numbers_average(int *numbers, int size); // calcula a média e retorna o valor
void numbers_show(int *numbers, int size); // exibe os valores alocados
void numbers_destroy(int *numbers); // desaloca a variável alocada

int numbers_max(int *numbers, int size); // encontra o maior número
int numbers_min(int *numbers, int size); // encontra o menor número
void numbers_show_even(int *numbers, int size); // exibe os números pares
void numbers_show_odd(int *numbers, int size); // exibe os números ímpares
int numbers_sum(int *numbers, int size); // soma dos números (funcionalidade extra)


// **************************** Implementação ******************************

int *numbers_create(int size) {
    int *num = NULL;
    num = (int *)malloc(size * sizeof(int));
    if (num == NULL)
        return NULL;
    return num;
}

void numbers_read(int *numbers, int size) {
    if (numbers != NULL) {
        for (int i = 0; i < size; i++)
            numbers[i] = rand() % 50;
    }
}

float numbers_average(int *numbers, int size) {
    float sum = 0.0;
    if (numbers != NULL)
        for (int i = 0; i < size; i++)
            sum += numbers[i];
    if (size > 0)
        return sum / (float)size;
    return 0;
}

void numbers_show(int *numbers, int size) {
    printf("[");
    if (numbers != NULL) {
        for (int i = 0; i < size; i++)
            if (i == (size - 1))
                printf("%d", numbers[i]);
            else
                printf("%d, ", numbers[i]);
    }
    printf("]\n");
}

void numbers_destroy(int *numbers) {
    free(numbers);
}

int numbers_max(int *numbers, int size) {
    if (numbers == NULL || size == 0)
        return -1; // ou algum valor que indique erro
    int max = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] > max)
            max = numbers[i];
    }
    return max;
}

int numbers_min(int *numbers, int size) {
    if (numbers == NULL || size == 0)
        return -1; // ou algum valor que indique erro
    int min = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] < min)
            min = numbers[i];
    }
    return min;
}

void numbers_show_even(int *numbers, int size) {
    printf("Pares: [");
    int first = 1;
    for (int i = 0; i < size; i++) {
        if (numbers[i] % 2 == 0) {
            if (!first)
                printf(", ");
            printf("%d", numbers[i]);
            first = 0;
        }
    }
    printf("]\n");
}

void numbers_show_odd(int *numbers, int size) {
    printf("Ímpares: [");
    int first = 1;
    for (int i = 0; i < size; i++) {
        if (numbers[i] % 2 != 0) {
            if (!first)
                printf(", ");
            printf("%d", numbers[i]);
            first = 0;
        }
    }
    printf("]\n");
}

int numbers_sum(int *numbers, int size) {
    int sum = 0;
    if (numbers != NULL) {
        for (int i = 0; i < size; i++)
            sum += numbers[i];
    }
    return sum;
}


int main() {
    srand(time(NULL));
    int size = rand() % 100;
    if (size == 0) size = 10; // para garantir que tenha elementos

    int *numbers = numbers_create(size);
    if (numbers == NULL) {
        printf("Erro ao alocar memória\n");
        return 1;
    }

    numbers_read(numbers, size);
    numbers_show(numbers, size);

    float avg = numbers_average(numbers, size);
    printf("Média = %.2f\n", avg);

    int max = numbers_max(numbers, size);
    printf("Maior número = %d\n", max);

    int min = numbers_min(numbers, size);
    printf("Menor número = %d\n", min);

    numbers_show_even(numbers, size);
    numbers_show_odd(numbers, size);

    int sum = numbers_sum(numbers, size);
    printf("Soma dos números = %d\n", sum);

    numbers_destroy(numbers);
    return 0;
}
