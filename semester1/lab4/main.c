#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define nmax 20
#define lmax 100

int task1(char arr[nmax][lmax], int k, char subs[nmax * lmax][lmax], int subs_origin[]) {
    int col = 0;
    for (int i = 0; i < k; i++) {
        char c = arr[i][0];
        for (int j = 0; c != '\n' && c != '\0'; j++) {
            c = arr[i][j];
            char s = arr[i][j + 1];

            if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
                for (int l = j + 2; s != '\n' && s != '\0'; l++) {
                    s = arr[i][l];
                    if ((s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z')) {
                        int p;
                        for (p = 0; p < l - j - 1; p++) {
                            subs[col][p] = arr[i][j + 1 + p];
                        }
                        subs[col][p] = '\0';
                        subs_origin[col] = i;
                        col++;
                    }
                }
            }
        }
    }
    return col;
}

int task2(char substrs[lmax][lmax], int col) {
    int found = -1, min_digits = INT_MAX;

    for (int i = 0; i < col; i++) {
        int temp = 0;
        char *str_ptr = substrs[i];

        while (*str_ptr) str_ptr++;

        str_ptr--;

        while (isdigit(*str_ptr)) {
            temp++;
            str_ptr--;
        }

        if (temp < min_digits && temp != 0) {
            min_digits = temp;
            found = i;
        }
    }

    return found;
}

void task3(char str[lmax]) {
    char result[lmax * 2];
    int j = 0;

    for (int i = 0; str[i] != '\0';) {
        if ((unsigned char)str[i] >= 0xD0 && (unsigned char)str[i] <= 0xD1) {
            result[j++] = str[i];
            result[j++] = str[i + 1];
            result[j++] = str[i];
            result[j++] = str[i + 1];
            i += 2;
        } else {
            result[j++] = str[i++];
        }
    }

    result[j] = '\0';
    strcpy(str, result);
}

int main() {
    int temp, k;
    char strs[nmax][lmax];
    char subs[nmax * lmax][lmax];
    int subs_origin[nmax * lmax];
    int col = 0;

    printf("Лабораторная работа №4 Мишин Михаил БИТ241\n");
    printf("Задание 1 вариант 6\n");

    do {
        printf("Введите количество строк k: ");
        temp = scanf("%d", &k);
    } while (temp != 1 || k <= 0 || k > nmax);
    while (getchar() != '\n');

    printf("Введите строки:\n");
    for (int i = 0; i < k; i++) {
        printf("Строка %d: ", i + 1);
        fgets(strs[i], lmax, stdin);
        strs[i][strcspn(strs[i], "\n")] = '\0';
    }

    col = task1(strs, k, subs, subs_origin);

    if (col == 0) {
        printf("Такие подстроки не найдены.\n");
    } else {
        printf("Найдено %d подстрок:\n", col);
        for (int i = 0; i < col; i++) {
            printf("Подстрока: %s из строки %d\n", subs[i], subs_origin[i] + 1);
        }

        printf("\nЗадание 2 вариант 8\n");

        int result = task2(subs, col);

        if (result == -1) {
            printf("Не найдены подстроки с цифрами в конце.\n");
        } else {
            printf("Подстрока с минимальным количеством цифр в конце: %s из строки %d\n",
                   subs[result], subs_origin[result] + 1);

            printf("\nЗадание 3 вариант 7\n");

            printf("Исходная строка: %s\n", strs[subs_origin[result]]);
            task3(strs[subs_origin[result]]);
            printf("Преобразованная строка: %s\n", strs[subs_origin[result]]);
        }

    }

    return 0;
}
