#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define lmax 100

int main() {
    int z[lmax][lmax], n, m, x[lmax], k, buf, i, j, b[lmax], temp, nb, numbers;

    printf("Лабораторная работа №2 Мишин Михаил БИТ241\n");
    printf("Задание 1, вариант 1\n");
    // Задание 1 ------------------------------------------------------------------------

    do {
        printf("Введите число строк и столбцов матрицы Z: ");
        buf = scanf("%d %d", &n, &m);
        while (getchar() != '\n');
    } while (n <= 0 || m <= 0 || n >= lmax || m >= lmax || buf != 2);

    printf("Введите матрицу %d на %d элементов:\n", n, m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &z[i][j]);
        }
    }

    do {
        printf("Введите длину массива X: ");
        buf = scanf("%d", &k);
        while (getchar() != '\n');
    } while (k <= 0 || k >= lmax || buf != 1);

    printf("Введите массив X из %d элементов:\n", k);
    for (i = 0; i < k; i++) {
        scanf("%d", &x[i]);
    }

    for (i = 0; i < n; i++) {
        int max_val = abs(z[i][0]);
        int max_index = 0;

        for (j = 1; j < m; j++) {
            if (abs(z[i][j]) > max_val) {
                max_val = abs(z[i][j]);
                max_index = j;
            }
        }

        int flag = 0;
        for (j = 0; j < k; j++) {
            if (z[i][max_index] == x[j]) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            z[i][max_index] = 0;
        }
    }

    printf("Матрица Z:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", z[i][j]);
        }
        printf("\n");
    }

    // задание 2 ------------------------------------------------------------------------
    printf("Задание 2, вариант 8\n");
    do {
        printf("Введите длину массива B: ");
        buf = scanf("%d",&nb);
        while(getchar() != '\n');
    } while(nb <= 0 || nb >= lmax || buf != 1);

    printf("Введите массив B из %d элементов:\n",nb);
    for(i = 0; i < nb; i++) {
        scanf("%d",&b[i]);
    }

    for(i = 0; i < nb; i++) {
        temp = b[i];
        numbers = 0;
        while(temp/10!=0) {
            numbers++;
            temp/=10;
        }
        temp = b[i]%10;
        b[i] = b[i]/10 + (temp * (int)pow(10,numbers));
    }

    printf("Массив B:\n");
    for(i = 0; i < nb; i++) {
        printf("%-8d",b[i]);
    }

    return 0;
}
