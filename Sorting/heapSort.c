#include<stdio.h>
//Heap sort

int left(int i) { 
    return 2 * i + 1;
}
int right(int i) { 
    return 2 * i + 2;
}


void swap(int *a, int *b) { 
    int temp = *a;
    *a = *b;
    *b = temp;
}

void MaxHeapify(int A[], int i, int n) { 
    int l = left(i); 
    int r = right(i); 
    int largest = i;

    if (l < n && A[l] > A[largest]) { 
        largest = l;
    }

    if (r < n && A[r] > A[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(&A[i], &A[largest]); 
        MaxHeapify(A, largest, n);
    }
}

void BuildHeap(int A[], int n) { 
    for (int i = n / 2 - 1; i >= 0; i--) { 
        MaxHeapify(A, i, n);
    }
}

void HeapSort(int A[], int n) { 
    BuildHeap(A, n);
    for (int i = n - 1; i > 0; i--) { 
        swap(&A[0], &A[i]); 
        MaxHeapify(A, 0, i); 
    }
}

int main() {
    int n;
    printf("Enter the size of the array (positive integer): ");
    scanf("%d",&n);
    int A[n];
    for (int i = 0; i < n; i++) {
        A[i] = rand(); 
    }
    HeapSort(A, n);
    printf("Sorted array:\n"); 
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}