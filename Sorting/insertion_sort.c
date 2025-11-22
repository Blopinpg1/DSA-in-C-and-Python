#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define max 100

void insertion_sort(int A[],int n)
{
    for (int i =0;i<n;i++)
    {
        int temp = A[i];
        int j = i-1;
        while(j>=0 && temp<A[j])
        {
            A[j+1] = A[j];
            j = j-1;
        }
        A[j+1] = temp;
    }
}

void display(int A[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}

int main()
{ time_t start,end ;
    double  time_difference;
    int i, A[max],n;
    printf("Enter n: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        A[i] = rand();
    }
    display(A,n);
    start = time(NULL);
    insertion_sort(A,n);
    end = time(NULL);
    display(A,n);
    
    time_difference = difftime(end,start);
    printf("%lf",time_difference);
    return 0;
}
