#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int a[200000];
void sort(int *a, int n)
{
    int i,j,min,temp;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
            if(a[j]<a[min])
               min=j;
       temp=a[i];
       a[i]=a[min];
       a[min]=temp;
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
