#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100000

void bubble_sort(int A[], int n){
    int i,j,temp;
    for ( i = 0; i < n-1; i++)
    {
        for ( j = 0; j < n-i-1; j++)
        {
            if (A[j]>A[j+1])
            {
                temp = A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
            
        }
        
    }
    
}

void display(int A[], int n){
    int i;
    for ( i = 0; i < n; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
    
}




int main(){
    int i,A[MAX],n;
     time_t start, end;
     double seconds;
    printf("Enter n: ");
    scanf("%d", &n);
    for ( i = 0; i < n; i++)
    {
       A[i] = rand();
    }
    display(A,n);
    start = time(NULL);
    bubble_sort(A,n);
    end = time(NULL);
    display(A,n);
    printf("\n\n");
    seconds = difftime(end, start);
    printf("%lf ", seconds);
    return 0;
    
}