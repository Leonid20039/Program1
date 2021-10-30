// 112-Чудновский-Леонид
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 10000

// Обмен местами элементов
void swap(double* a, double* b) {
    double t = *a;
    *a = *b;
    *b = t;
}

// Функция сортирует часть массива, лежащую между l и h
int partition(double arr[], int l, int h) {
	double x = arr[h];
    int i = (l - 1);

    for (int j = l; j <= h - 1; j++) {
        if (arr[j] <= x) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return (i + 1);
}

// Сортировка части массива
void q_sort(double arr[], int l, int h) {
    int stack[M];           // Создаем стек
    int top = -1;           // Вершина стека
    stack[++top] = l;    
    stack[++top] = h;    

    while (top >= 0) {      // Сортируем пока стек не пуст
        h = stack[top--];
        l = stack[top--];

        int p = partition(arr, l, h);

        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }

        if (p + 1 < h) {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}