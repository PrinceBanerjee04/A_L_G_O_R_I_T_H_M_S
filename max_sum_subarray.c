// Dynamic Programming
#include<stdio.h>
#include<stdlib.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}
int MaxSumDP(int arr[],int n)
{
    int current_sum = arr[0], max_sum = arr[0];
    for(int i=1;i<n;i++)
    {
        current_sum = max(arr[i],current_sum+arr[i]);
        max_sum = max(current_sum,max_sum);
    }
    return max_sum;
}
int main()
{
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);
    int arr[n],i;
    printf("Enter array elements: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nGiven Array : ");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\nMaximum Sum: %d",MaxSumDP(arr,n));
    return 0;
}
