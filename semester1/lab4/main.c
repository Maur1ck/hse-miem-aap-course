#include <stdio.h>
#include <stdbool.h>

#define nmax 20
#define lmax 100

void extract_substring(const char *start_ptr, const char *end_ptr, char *result) {
    char *res_ptr = result;
    while (start_ptr < end_ptr) {
        *res_ptr = *start_ptr;
        res_ptr++;
        start_ptr++;
    }
    *res_ptr = '\0';
}

int is_latin_letter(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

void task1(char strs[nmax][lmax], int k, int *num_of_substrs) {
    int i, j;
    char new_strs[nmax][lmax], test[nmax][lmax], *p1, *p2;
    bool Flag = false;

    for (i = 0; i < k; i++) {
        p1 = NULL;
        j = 0;

        for (p2 = strs[i]; *p2; p2++) {
            if (is_latin_letter(*p2) && p1 == NULL) {
                p1 = p2;
            }
            if (!is_latin_letter(*p2)) {
                Flag = true;
            }
            if (is_latin_letter(*p2) && Flag) {
                extract_substring(p1 + 1, p2, new_strs[j]);
                (*num_of_substrs)++;
                j++;
                Flag = false;
                p1 = p2;
            } else {
                if (!Flag) {
                    p1 = p2;
                }
            }

        }
    }

    for (i = 0; i < *num_of_substrs; i++) {
        printf("%s\n", new_strs[i]);
    }
}

int main() {
    int temp, k, i, num_of_substrs = 0;
    char strs[nmax][lmax];

    printf("Лабораторная работа №4 Мишин Михаил БИТ241\n");
    printf("Задание 1 вариант 6\n");

    do {
        printf("Введите количество строк k: ");
        temp = scanf("%d", &k);
    } while (temp != 1 || k <= 0 || k > lmax);
    while (getchar() != '\n');

    printf("Введите строки:\n");
    for (i = 0; i < k; i++) {
        printf("Строка %d: ", i + 1);
        gets(strs[i]);
    }

    task1(strs, k, &num_of_substrs);

    printf("Количество подстрок: %d\n", num_of_substrs);

    return 0;
}
