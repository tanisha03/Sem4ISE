#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int a[20000],n;
void swap(int i,int j)
{
    int temp;
    temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
int partition(int low,int high)
{
    int pivot=a[high];
    int index=low;
    for(int i=low;i<=high;i++)
    {
        if(a[i]<pivot)
        {
            swap(i,index);
            index++;
        }
    }
    swap(index,high);
    return index;
}
void sort(int low,int high)
{
    if(low<high)
    {
        int part=partition(low,high);
        sort(low,part-1);
        sort(part+1,high);
    }
}
void main()
{
    int i;
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