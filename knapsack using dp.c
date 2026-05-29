#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    int n, W;
    int i, w;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int wt[n], val[n];

    printf("Enter weights:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &wt[i]);

    printf("Enter values (profits):\n");
    for(i = 0; i < n; i++)
        scanf("%d", &val[i]);

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    int dp[n + 1][W + 1];

    for(i = 0; i <= n; i++)
    {
        for(w = 0; w <= W; w++)
        {
            if(i == 0 || w == 0)
                dp[i][w] = 0;

            else if(wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]],
                               dp[i - 1][w]);

            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    printf("\nMaximum Profit = %d\n", dp[n][W]);

    printf("Items selected (0-based index): ");

    i = n;
    w = W;

    while(i > 0 && w > 0)
    {
        if(dp[i][w] != dp[i - 1][w])
        {
            printf("%d ", i - 1);
            w = w - wt[i - 1];
        }
        i--;
    }

    printf("\n");

    return 0;
}
