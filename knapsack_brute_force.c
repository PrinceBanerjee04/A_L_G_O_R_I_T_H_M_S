#include <stdio.h>
#define MAX_ITEMS 10

typedef struct
{
    int weight;
    int value;
} Item;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapsack(Item items[], int n, int capacity)
{
    if (n == 0 || capacity == 0)
    {
        return 0;
    }

    if (items[n - 1].weight > capacity)
    {
        return knapsack(items, n - 1, capacity);
    }
    else
    {
        return max(knapsack(items, n - 1, capacity), items[n - 1].value + knapsack(items, n - 1, capacity - items[n - 1].weight));
    }
}
int main()
{
    Item items[MAX_ITEMS] = {{5, 20}, {3, 40}, {4, 30}};

    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 10;

    int max_value = knapsack(items, n, capacity);
    printf("Maximum value that can be obtained: %d\n", max_value);

    return 0;
}
