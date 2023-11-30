#include <stdio.h>
#include <iostream>
#include <windows.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
    SetConsoleOutputCP(1251);

    int sr_ar, n;
    int cnt_polozh = 0, sum_polozh = 0;
    int *mas; // указатель на int для массива
    printf("Введите размерность массива mas:\n");
    scanf_s("%d", &n);

    // Выделение памяти
    mas = (int*)malloc(n * sizeof(int));

    //Ввод элементов массива с клавиатуры
    for (int i = 0; i < n; i++) {
        printf("Введите число для добавления в массив:\n");
        printf("mas[%d] = ", i);
        scanf_s("%d", &mas[i]);
    }
    
    //Подсчет кол-ва полож. чисел и их суммы
    for (int i = 0; i < n; i++) {
        if (mas[i] > 0) {
            cnt_polozh++;
            sum_polozh += mas[i];
        }
    }
    sr_ar = sum_polozh / cnt_polozh;
    
    //Замена отриц. чисел ср. арифметическим полож. чисел
    for (int i = 0; i < n; i++) {
        if (mas[i] < 0) {
            mas[i] = sr_ar;
        }
    }
    
    //Вывод элементов массива
    for (int i = 0; i < n; i++) {
        printf("%d ", mas[i]);
    }
    return 0;
}

