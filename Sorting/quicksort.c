#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define max 100

int partition(int A[],int l,int r)
{
    int x = l;
    int y = r;
    int pivot = A[l];
    while(x<y)
    {
        while(A[x]<=pivot && x<=r)
        {
            x++;
        }
        while(A[y]>pivot)
        {
            y--;
        }
        if(x<y)
        {
            int temp;
            temp = A[l];
            A[l] = A[y];
            A[y] = temp;
        }
    }
    int temp;
    temp = A[l];
    A[l] = A[y];
    A[y] = temp;
    return y;
}

void quick_sort(int A[],int l, int r)
{
    if(l<r)
    {
        int p = partition(A,l,r);
        quick_sort(A,l,p-1);
        quick_sort(A,p+1,r);
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
{
    int i, A[max],n;
    srand(time(NULL));
    time_t start,end;
    double second;
    printf("Enter n: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        A[i] = rand();
    }
    display(A,n);
    start = time(NULL);
    quick_sort(A,0,n-1);
    end = time(NULL);
    second = difftime(end,start);
    display(A,n);
    return 0;
}