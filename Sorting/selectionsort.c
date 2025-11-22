#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#define MAX 100000

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int least= i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[least]) {
                least = j;
            }
        }
        if(i!=least)
        {
            int temp = arr[i];
            arr[i] = arr[least];
            arr[least] = temp;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
   time_t start, end;
     double seconds;
     int n,i;
     int arr[MAX];
    printf("Enter n:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {  
        arr[i] = rand();
    }
    printf("Original array: ");
    printArray(arr, n);
     start = time(NULL);
    selectionSort(arr, n);
     end = time(NULL);
    
    printf("Sorted array: ");
    printArray(arr, n);

    seconds = difftime(end, start);
    printf("%lf ", seconds);
    
return 0;
}