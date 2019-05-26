#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int a[200000];
void sort(int *a, int n)
{
    int i,j,min,temp;
    for(i=0;i<=n-2;i++)
    {
        for(j=0;j<=n-i-1;j++)
         {
            if(a[j+1]<a[j])
            {
                temp=a[j];
       a[j]=a[j+1];
       a[j+1]=temp;
            }
         }

    }
}
void main()
{
    int n;clock_t start,end;
    double t;
    printf("enter the size\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        a[i]=rand()%1000;
    start=clock();
    sort(a,n);
    end=clock();
    t=(double)(end-start)/CLOCKS_PER_SEC;
    printf("%f\n",t);

}
