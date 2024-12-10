#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define lmax 100

void rewrite(char filename[], char filenameOut[]) {
    char buffer[lmax], temp;
    FILE *file = fopen(filename, "r");
    FILE *fileOut = fopen(filenameOut, "w");

    if (file == NULL || fileOut == NULL) {
        perror("Ошибка открытия файла");
        exit(1);
    }

    while (fscanf(file, "%s", buffer) != EOF) {
        int length = strlen(buffer);

        for (int i = 0; i < length - 1; i += 2) {
            temp = buffer[i];
            buffer[i] = buffer[i + 1];
            buffer[i + 1] = temp;
        }

        fprintf(fileOut, "%s\n", buffer);
        printf("%s\n", buffer);
    }

    fclose(file);
    fclose(fileOut);
}

int main() {
    char filename[lmax], filenameOut[lmax];

    printf("Лабораторная работа №5 Мишин Михаил БИТ241\n");
    printf("Задание 2 вариант 9\n");

    printf("Введите название файла, откуда будут считываться строки: ");
    fgets(filename, lmax, stdin);
    filename[strcspn(filename, "\n")] = '\0';

    printf("Введите название файла, куда будет вписан результат: ");
    fgets(filenameOut, lmax, stdin);
    filenameOut[strcspn(filenameOut, "\n")] = '\0';

    rewrite(filename, filenameOut);

    return 0;
}
