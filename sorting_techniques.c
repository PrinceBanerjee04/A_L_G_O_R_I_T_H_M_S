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
