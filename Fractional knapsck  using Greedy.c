#include <stdio.h>

struct Item
{
    int weight;
    int value;
    float ratio;
};

void swap(struct Item *a, struct Item *b)
{
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n, i, j;
    float capacity, totalValue = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    printf("Enter weight and value of items:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d %d", &items[i].weight, &items[i].value);
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(items[j].ratio < items[j + 1].ratio)
            {
                swap(&items[j], &items[j + 1]);
            }
        }
    }

    printf("\nItems taken:\n");

    for(i = 0; i < n; i++)
    {
        if(items[i].weight <= capacity)
        {
            capacity -= items[i].weight;
            totalValue += items[i].value;

            printf("Full item taken (W=%d, V=%d)\n", items[i].weight, items[i].value);
        }
        else
        {
            float fraction = capacity / items[i].weight;
            totalValue += items[i].value * fraction;

            printf("Fraction taken: %.2f of item (W=%d, V=%d)\n",
                   fraction, items[i].weight, items[i].value);

            break;
        }
    }

    printf("\nMaximum Profit = %.2f\n", totalValue);

    return 0;
}
