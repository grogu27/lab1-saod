#include "1.h"

void print(uint32_t arr[], int len){
  for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void swap(uint32_t *a, uint32_t *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
int getrand(int min, int max) {
  return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

double wtime() {
  struct timeval t;
  gettimeofday(&t, NULL);
  return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int getMax(uint32_t arr[], int n) {
  int max = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

int getmin(uint32_t arr[], int n) {
  int min = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] < min) {
      min = arr[i];
    }
  }
  return min;
}
void oddEvenSort(uint32_t arr[], int n) {
  int sorted = 0;
  while (!sorted) {
    sorted = 1;
    for (int i = 0; i < n - 1; i += 2) 
      if (arr[i] > arr[i + 1]) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
        sorted = 0;
      }
    
    for (int i = 1; i < n - 1; i += 2) 
      if (arr[i] > arr[i + 1]) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
        sorted = 0;
      } 
  }
}
 //Использование сортировки подсчетом для сортировки элементов по разрядом
void countingSort(uint32_t array[], int size, int place) {
  int output[size + 1];
  int max = (array[0] / place) % 10;

  for (int i = 1; i < size; i++) {
    if (((array[i] / place) % 10) > max)
      max = array[i];
  }
  int count[max + 1];

  for (int i = 0; i < max; ++i)
    count[i] = 0;

  for (int i = 0; i < size; i++)
    count[(array[i] / place) % 10]++;
    
  for (int i = 1; i < 10; i++)
    count[i] += count[i - 1];

  // Размещение элементов в отсортированном порядке
  for (int i = size - 1; i >= 0; i--) {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
  }

  for (int i = 0; i < size; i++)
    array[i] = output[i];
}

void radixSort(uint32_t array[], int size) {
  int max = getMax(array, size);
  for (int place = 1; max / place > 0; place *= 10)
    countingSort(array, size, place);
}

//построение пирамиды
void heapify(uint32_t arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
    if (largest != i) {
      // поменяться местами с потомком, имеющим большее значение и
      swap(&arr[i], &arr[largest]);
      // вызываем heapify для дочернего элемента
      heapify(arr, n, largest);
    }
  }

void heapSort(uint32_t arr[], int n) {
  // построение пирамиды
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);
  // сортировка
  for (int i = n - 1; i >= 1; i--) {
    swap(&arr[0], &arr[i]);
  // Вызываем процедуру heapify на уменьшенной куче
    heapify(arr, i, 0);
  }
}