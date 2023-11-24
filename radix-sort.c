#include <stdio.h>
 
#define MAX_LEN 100
 
static int get_max(int array[], int n) 
{ 
    int max = array[0]; 
    for (int i = 1; i < n; i++) 
        if (array[i] > max) 
            max = array[i]; 
    return max; 
}
 
static void count_sort(int array[], int n, int exp) 
{ 
    int output[n];
    int i, count[10] = {0};
 
    for (i = 0; i < 10; i++) {
        count[i] = 0;
    }
 
    for (i = 0; i < n; i++) {
        count[(array[i] / exp) % 10]++;
    }
 
    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    } 
 
    for (i = n - 1; i >= 0; i--) { 
        output[count[(array[i] / exp) % 10] - 1] = array[i]; 
        count[(array[i] / exp) % 10]--; 
    }
 
    for (i = 0; i < n; i++) 
        array[i] = output[i]; 
} 
 
static void sort(int array[], int n) 
{ 
    int m = get_max(array, n); 
 
    for (int exp = 1; m / exp > 0; exp *= 10) 
        count_sort(array, n, exp); 
} 
 
static void print_array(int *array, int len)
{
    int i;
 
    for (i = 0; i < len; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
 
int main()
{
    int array[MAX_LEN], len, i;
 
    printf("What's the length of the array? Maximum lenght is %d\n", MAX_LEN);
    scanf("%d", &len);
 
    printf("Gimme the %d elements\n", len);
    for (i = 0; i < len; i++) {
    scanf("%d", &array[i]);
    }
 
    printf("Nonsorted array: ");
    print_array(array, len);
 
    sort(array, len);
 
    printf("Sorted array: ");
    print_array(array, len);
 
    return 0; 
}
