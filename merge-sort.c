#include <stdio.h>
 
#define MAX_LEN 100
 
static void merge(int arr[], int left, int mid, int right) 
{ 
    int i, j, k; 
    int n1 = mid - left + 1; 
    int n2 = right - mid; 
 
    int aux_left[n1], aux_right[n2]; 
 
    for (i = 0; i < n1; i++) 
        aux_left[i] = arr[left + i]; 
    for (j = 0; j < n2; j++) 
        aux_right[j] = arr[mid + 1 + j]; 
 
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) { 
        if (aux_left[i] <= aux_right[j]) { 
            arr[k] = aux_left[i]; 
            i++; 
        } 
        else { 
            arr[k] = aux_right[j]; 
            j++; 
        } 
        k++; 
    } 
 
    while (i < n1) { 
        arr[k] = aux_left[i]; 
        i++; 
        k++; 
    } 
 
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
}
 
static void sort(int arr[], int left, int right)
{
    if (left < right) {
        int mid = left + (right - left) / 2; 
 
        sort(arr, left, mid); 
        sort(arr, mid + 1, right); 
 
        merge(arr, left, mid, right); 
    } 
}
 
static void print_array(int *arr, int len)
{
    int i;
 
    for (i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
 
int main()
{
    int arr[MAX_LEN], len, i;
 
    printf("What's the length of the array? Maximum lenght is %d\n", MAX_LEN);
    scanf("%d", &len);
 
    printf("Gimme the %d elements\n", len);
    for (i = 0; i < len; i++) {
    scanf("%d", &arr[i]);
    }
 
    printf("Nonsorted array: ");
    print_array(arr, len);
 
    sort(arr, len);
 
    printf("Sorted array: ");
    print_array(arr, len);
 
    return 0; 
}
