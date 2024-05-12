//USING BRUTE FORCE

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

int knapsack(Item items[], int n, int capacity, int *subset) 
{
    if (n == 0 || capacity == 0) 
    {
        return 0;
    }

    if (items[n - 1].weight > capacity) 
    {
        return knapsack(items, n - 1, capacity, subset);
    } else 
    {
        int include = items[n - 1].value + knapsack(items, n - 1, capacity - items[n - 1].weight, subset - 1);
        int exclude = knapsack(items, n - 1, capacity, subset);

        if (include > exclude) 
        {
            *subset = n - 1;
            return include;
        } else 
        {
            return exclude;
        }
    }
}

int main() {
    Item items[MAX_ITEMS] = {{2, 10},
        {3, 15},
        {5, 25},
        {7, 30}
    };

    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 10;
    int subset[MAX_ITEMS] = {0};

    int max_value = knapsack(items, n, capacity, subset);
    printf("Maximum value that can be obtained: %d\n", max_value);

    printf("Selected items (index): ");
    for (int i = 0; i < n; i++) {
        if (subset[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
