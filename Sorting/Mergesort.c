#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define MAX 100000


void merge(int A[], int l, int m, int r);

void merge_sort(int A[], int l, int r){
    if (l < r)
    {
        int m = l + (r - l) / 2;
        merge_sort(A, l, m);
        merge_sort(A, m + 1, r);
        merge(A, l, m, r);
    }
}

void merge(int A[], int l, int m, int r){
    int i = l;
    int j = m + 1;
    int k = l;
    int B[MAX];
    while (i <= m && j <= r)
    {
        if (A[i] <= A[j]) {
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }
    while (i <= m) {
        B[k++] = A[i++];
    }
    while (j <= r) {
        B[k++] = A[j++];
    }
    for (i = l; i <= r; i++) {
        A[i] = B[i];
    }
}
  void display(int A[], int n){
        int i;
        for ( i = 0; i < n; i++)
        {
            printf("%d ", A[i]);

        }
        printf("\n\n");

        
    }


int main(){
    time_t start,end;
    double timediff;
    int i,A[MAX], n, l=0, r;
    printf("Enter n");
    scanf("%d",&n);
    for ( i = 0; i < n; i++)
    {
      A[i] = rand();
    }
    r =n-1;
    display(A,n);
    start = time(NULL);
    merge_sort(A,l,r);
    end = time(NULL);
    display(A,n);
    timediff = difftime(end,start);
    printf("Time : %lf seconds \n",timediff );
    return 0;
}