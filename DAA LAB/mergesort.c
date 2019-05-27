#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int a[20000],b[20000],c[20000],n;
void merge(int low,int mid,int high)
{
    int i,j,k;
    for(i=low;i<=mid;i++)
        b[i]=a[i];
    for(j=mid+1;j<=high;j++)
        c[j]=a[j];
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high)
    {
        if(b[i]<c[j])
            a[k++]=b[i++];
        else
            a[k++]=c[j++];
    }
    while(i<=mid)
        a[k++]=b[i++];
    while(j<=high)
        a[k++]=c[j++];
}
void sort(int low,int high)
{
    if(low<high)
    {
    int mid=(low+high)/2;
    sort(low,mid);
    sort(mid+1,high);
    merge(low,mid,high);
    }
}
void main()
{
    int i,j;
    clock_t start,end;
    double t;
    printf("enter the value of n\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        a[i]=rand()%1000;
    start=clock();
    sort(0,n-1);
    end=clock();
    t=(double)(end-start)/CLOCKS_PER_SEC;
    for(i=0;i<n;i++)
        printf("%d  ",a[i]);
    printf("\nTime is %f  \n",t);
}