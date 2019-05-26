#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int a[200000];
void swap(int *a,int x,int y)
{
    int t;
    t=a[x];
    a[x]=a[y];
    a[y]=t;
}
int partition(int *a,int low,int high)
{
    int pivot=a[high];
    int pivotindex=low;
    for(int i=low;i<high;i++)
    {
        if(a[i]<pivot)
        {
            swap(a,i,pivotindex);
            pivotindex++;
        }
    }
    swap(a,high,pivotindex);
    return pivotindex;

}

void sort(int *a, int low,int high)
{
  int part;
  if(low<high)
  {
      part=partition(a,low,high);
      sort(a,low,part-1);
      sort(a,part+1,high);
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
    //for(int i=0;i<n;i++)
        //printf("%d   ",a[i]);
    start=clock();
    sort(a,0,n-1);
    end=clock();
    t=(double)(end-start)/CLOCKS_PER_SEC;
    printf("%f\n",t);
    //for(int i=0;i<n;i++)
        //printf("%d   ",a[i]);


}
