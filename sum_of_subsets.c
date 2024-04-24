//BACKTRACKING
#include <stdio.h>

void sum_of_subsets(int numbers[], int target_sum, int subset[], int subset_size, int index, int sum_so_far) 
{
    if (sum_so_far == target_sum) {
        printf("{ ");
        for (int i = 0; i < subset_size; i++) 
        {
            printf("%d ", subset[i]);
        }
        printf("}\n");
        return;
    }
    if (index >= sizeof(numbers)/sizeof(numbers[0]) || sum_so_far > target_sum) 
    {
        return;
    }
    sum_of_subsets(numbers, target_sum, subset, subset_size, index + 1, sum_so_far);
    subset[subset_size] = numbers[index];
    sum_of_subsets(numbers, target_sum, subset, subset_size + 1, index + 1, sum_so_far + numbers[index]);
}

int main() 
{
    int numbers[] = {10, 7, 5, 18, 12, 20, 15};
    int target_sum = 35;
    int subset[sizeof(numbers)/sizeof(numbers[0])];

    sum_of_subsets(numbers, target_sum, subset, 0, 0, 0);

    return 0;
}
