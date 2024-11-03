#include <stdio.h>

int n,k,sum=0;
int a,i;

int main()
{
    scanf("%d %d",&n,&k);
    for (i=0 ; i<n ; i++)
    {
        scanf("%d",&a);

    if (a % k != 0)
    {
        sum+=a;
    }
    }
    printf("%d\n", sum);
    return 0;
}