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
