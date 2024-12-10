#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define lmax 100


void writeFile(char filename[]) {
    char buffer[lmax];
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Ошибка открытия файла\n");
        exit(1);
    }
    printf("Введите строки для записи в файл (введите пустую строку для завершения):\n");

    while (1) {
        fgets(buffer, lmax, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        if (strcmp(buffer, "") == 0) {
            break;
        }

        fprintf(file, "%s\n", buffer);
    }

    printf("Запись завершена. Файл сохранен как '%s'.\n", filename);

    fclose(file);
}


void calculate(char filename[]) {
    float buffer = 0;
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Ошибка открытия файла\n");
        exit(1);
    }

    int count = 0;
    float sum = 0.0;

    while (!feof(file)) {
        int result = fscanf(file, "%f", &buffer);
        if (result == 1) {
            if (buffer < 0) {
                count++;
                sum += buffer;
            }
        } else if (result == 0) {
            char invalidInput[256];
            fscanf(file, "%255s", invalidInput);
            printf("Пропущены некорректные данные: %s\n", invalidInput);
        } else if (result == EOF) {
            break;
        }
    }

    fclose(file);

    if (count == 0) {
        printf("Нет отрицательных чисел.\n");
    } else {
        printf("Среднее арифметическое: %f\n", sum / count);
    }
}


int main() {
    char filename[lmax];

    printf("Лабораторная работа №5 Мишин Михаил БИТ241\n");
    printf("Задание 1 вариант 6\n");

    printf("Введите название файла: ");
    fgets(filename, lmax, stdin);
    filename[strcspn(filename, "\n")] = '\0';

    writeFile(filename);
    calculate(filename);

    return 0;
}

