#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int a[200000],b[200000],c[200000];
void simple(int *a,int low,int mid,int high)
{
    int i,j,x,k;
    for(int i=low;i<=mid;i++)
        b[i]=a[i];
    for(int i=mid+1;i<=high;i++)
        c[i]=a[i];
    i=low,j=mid+1;k=low;
    while(i<=mid && j<=high)
    {
        if(b[i]<c[j])
        {
            a[k]=b[i];
            i++;
            k++;
        }
        else
        {
            a[k]=c[j];
            j++;
            k++;
        }
    }
    while(i<=mid)
        a[k++]=b[i++];
    while(j<=high)
        a[k++]=c[j++];
}
void sort(int *a, int low,int high)
{
  int mid;
  if(low<high)
  {
      mid=(low+high)/2;
      sort(a,low,mid);
      sort(a,mid+1,high);
      simple(a,low,mid,high);
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
    sort(a,0,n-1);
    end=clock();
    t=(double)(end-start)/CLOCKS_PER_SEC;
    printf("%f",t);
    for(int i=0;i<n;i++)
        printf("%d   ",a[i]);


}
