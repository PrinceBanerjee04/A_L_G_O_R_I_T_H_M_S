#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int a[], int l1, int u1, int l2, int u2)
{
    int p, q, j, n;
    int d[100];
    p = l1;
    q = l2;
    n = 0;
    while (p <= u1 && q <= u2)
    {
        if (a[p] < a[q])
            d[n++] = a[p++];
        else
            d[n++] = a[q++];
    }
    while (p <= u1)
    {
        d[n++] = a[p++];
    }
    while (q <= u2)
    {
        d[n++] = a[q++];
    }
    for (q = l1, n = 0; q <= u2; q++, n++)
    {
        a[q] = d[n];
    }
}

// Merge Sort function
void mergesort(int a[],int lower,int upper)
{
    int mid;
    if (upper > lower)
    {
        mid = (upper + lower) / 2;
        mergesort(a, lower, mid);
        mergesort(a, mid + 1, upper);
        merge(a, lower, mid, mid + 1, upper);
    }
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n = 500;
    int arr1[n], arr2[n];
    clock_t start, end;
    double mergeSortTime, bubbleSortTime;

    for (int i = 0; i < n; i++)
    {
        arr1[i] = rand() % 1000;
        arr2[i] = arr1[i];
    }

    start = clock();
    mergesort(arr1, 0, n - 1);
    end = clock();
    mergeSortTime = ((double)(end - start)) / CLOCKS_PER_SEC;

    start = clock();
    bubbleSort(arr2, n);
    end = clock();
    bubbleSortTime = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array using Merge Sort:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\nMerge Sort Time: %f seconds\n\n", mergeSortTime);

    printf("Sorted array using Bubble Sort:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("\nBubble Sort Time: %f seconds\n", bubbleSortTime);

    return 0;
}
