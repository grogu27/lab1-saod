#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <inttypes.h>
int getMax(uint32_t arr[], int n);
double wtime();
int getrand(int min, int max);
void oddEvenSort(uint32_t arr[], int n);
void countingSort(uint32_t array[], int size, int place);
void radixSort(uint32_t array[], int size);
void swap(uint32_t *a, uint32_t *b);
void heapSort(uint32_t arr[], int n);
void heapify(uint32_t arr[], int n, int i);
void print(uint32_t arr[], int len);