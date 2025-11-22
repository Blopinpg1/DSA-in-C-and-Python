#include <stdio.h>
#include <time.h>

void TOH(int n, char src, char dst, char tmp)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", src, dst);

        return;
    }

    TOH(n - 1, src, tmp, dst);
    printf("Move disk %d from %c to %c\n", n, src, dst);
    TOH(n - 1, tmp, dst, src);
}

int main()
{
    time_t start, end;
    double seconds;
    int n;
    printf("Enter the number of disks:");
    scanf("%d", &n);
    start = time(NULL);
    TOH(n, 'A', 'C', 'B');
    end = time(NULL);
    seconds = difftime(end, start);
    printf("%lf", seconds);
    return 0;
}
