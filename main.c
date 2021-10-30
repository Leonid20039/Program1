// 112-Чудновский-Леонид
// Сортировка массива с помощью алгоритма qsort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#define N 100000

int main(void) {
	char filename[120];	
	double mass[N];
	clock_t  start, end;	
	int i, j, a, Low = -10000, High = 10000 ;		
	float time;
	int n = 25000;	
	FILE* fin;	
		
	for (j = 0; j < 3; j++) {

		printf("Enter file name:");
		scanf("%s", filename);
		fin = fopen(filename, "w");
		// провекрка на возможность открыть файл
		if(!fin){
			printf("Unable to open %s\n", filename);
			return 1;
		}
		// заполнение массива случайными числами
		for(int i = 0; i < n; i++){
			mass[i] = random(Low, High);
			fprintf(fin, "%lf  ", mass[i]);
		}
		// сортировка
		start = clock();		
		q_sort(mass, 0, n - 1);		
		end = clock();					
		time = (float)(end - start) / CLK_TCK;	// время сортировки 
		check_sort(mass, n); // проверка на верность сорттировки

		for(int i = 0; i < n; i++){
			fprintf(fin, "%lf  ", mass[i]);
		}
		
		printf("Number of elements: %d\n", n);
		printf("Time sort: %f\n\n", time);
		n = n * 2;
	}

	return 0;
}