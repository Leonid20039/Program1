// 112-Чудновский-Леонид
// Проверка на правильность сортировки
#include <stdio.h>
void check_sort(double *mass, int n){
    int a = 0;
    for (int i = 0; i < n-1; i++){
        if(mass[i] > mass[i+1]){
            a = 1;
        }
    }
    if ( a == 0){
        printf("The mass is correctly sorted\n");
    }
    if (a == 1){
        printf("The mass is not correctly sorted\n");
    }
}

