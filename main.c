

#include <stdio.h>

int fact(int n)
{
    int i, f=1;
    for(i=1;i<=n;i++)
    f=f*i;
    return f;
}

int main()
{
    float diff[10][10],x,y,h,u,ux=1.0;
    int i,j,n;
    printf("enter the number of data:\n");
    scanf("%d",&n);
    printf("\nenter the value of x and y\n");
    for(i=0;i<n;i++)
    {
        printf("X%d=",i+1);
        scanf("%f",&diff[i][0]);
        printf("Y%d=",i+1);
        scanf("%f",&diff[i][1]);
    }
    for(j=2;j<=n;j++)
    for(i=0;i<n-1;i++)
    diff[i][j]=diff[i+1][j-1] - diff[i][j-1];
    printf("\nenter the value of x:\n");
    scanf("%f",&x);
    h=diff[1][0] - diff[0][0];
    u=(x - diff[0][0])/h;
    y=diff[0][1];
    for(i=1;i<n;i++)
    {
        ux = ux*(u-(i-1));
        y=y+(diff[0][i+1]*ux)/fact(i);
    }
    printf("\nthe value of function at x=%5.2f is %5.2f",x,y);
}
