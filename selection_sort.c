#include<stdio.h>

int main()
{
    int n;
    printf("Enter Array Size : ");
    scanf("%d",&n);
    int arr[n],i,j,temp,min;
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Given Array : ");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
            min=j;
        }
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
    
    printf("\nSorted Array : ");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
