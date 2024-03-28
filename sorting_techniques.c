void print_array(int arr[], int n)
{
    printf("[");
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        if (i < n - 1)
            printf(", ");
    }
    printf("]\n");
}

void bubble_sort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            bc++;
            if (arr[j] > arr[j + 1])
            {
                bs++;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        printf("After pass %d: ", i + 1);
        print_array(arr, n);
    }
}

void selection_sort(int arr[], int n)
{
    int i, j, temp, min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            sc++;
            if (arr[j] < arr[min])
                min = j;
        }
        ss++;
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
        printf("After pass %d: ", i + 1);
        print_array(arr, n);
    }
}

void insertion_sort(int arr[], int n)
{
    int i, j, temp, min;
    arr[0] = -999;
    for (i = 1; i <= n; i++)
    {
        temp = arr[i];
        min = i - 1;
        while (arr[min] > temp)
        {
            ic++;
            arr[min + 1] = arr[min];
            min--;
        }
        arr[min + 1] = temp;
        is++;
        printf("After pass %d: ", i + 1);
        print_array(arr, n);
    }
}

int main()
{
    clock_t start, end;
    double cpu_time_used;
    int n;
    printf("Enter Array Size : ");
    scanf("%d", &n);
    int arr[n], i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nEnter 1 for Bubble Sort, 2 for Selection Sort, 3 for Insertion Sort : ");
    int ch;
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        printf("Bubble Sort:\n");
        start = clock();
        bubble_sort(arr, n);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Execution Time : %lf\n", cpu_time_used);
        printf("Comparisons: %d\n", bc);
        printf("Swaps: %d\n", bs);
        break;

    case 2:
        printf("Selection Sort:\n");
        start = clock();
        selection_sort(arr, n);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Execution Time : %lf\n", cpu_time_used);
        printf("Comparisons: %d\n", sc);
        printf("Swaps: %d\n", ss);
        break;

    case 3:
        printf("Insertion Sort:\n");
        start = clock();
        insertion_sort(arr, n);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Execution Time : %lf\n", cpu_time_used);
        printf("Comparisons: %d\n", ic);
        printf("Swaps: %d\n", is);
        break;
    default:
        printf("WRONG CHOICE!!!");
    }
    return 0;
}
