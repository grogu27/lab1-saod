#include "1.h"

int main()
{
    int len = 1000;
    int end = 1000;
    int min_rand = 0, max_rand = 100000;
    printf("Size\t\tOddEvenSort\t\tradixSort\t\theapSort\n");
    while (len <= end){
      uint32_t *radix_arr = malloc(sizeof(uint32_t) * len);
      uint32_t *heap_arr = malloc(sizeof(uint32_t) * len);
      uint32_t *oddEven_arr = malloc(sizeof(uint32_t) * len);
      for (int i = 0; i < len; i++) {
      int element = getrand(min_rand, max_rand);
      radix_arr[i] = element;
      heap_arr[i] = element;
      oddEven_arr[i] = element;
    }
      double start;
      double func_time[3] = {0, 0, 0};

      //oddEven
      start = wtime();
      oddEvenSort(oddEven_arr, len);
      func_time[0] = wtime() - start;
      //print(oddEven_arr, len);

      //radix
      start = wtime();
      radixSort(radix_arr, len);
      func_time[1] = wtime() - start;
      //print(radix_arr, len);

      //heap
      start = wtime();
      heapSort(heap_arr, len);
      func_time[2] = wtime() - start;
      printf("%d\t\t%lf\t\t%lf\t\t%lf\n", len, func_time[0], func_time[1], func_time[2]);
      print(heap_arr, len);
      len += 50000;
      free(heap_arr);
      free(oddEven_arr);
      free(radix_arr);
    }
    
 
    
    return 0;
}