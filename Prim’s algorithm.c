#include <stdio.h>

#define MAX 10
#define INF 99999

int main()
{
    int n, i, j, u, v, min, cost[MAX][MAX];
    int visited[MAX] = {0};
    int edge = 1;
    int minCost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix (use %d for INF):\n", INF);
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    visited[0] = 1;

    printf("\nEdges in MST:\n");

    while(edge < n)
    {
        min = INF;
        u = -1;
        v = -1;

        for(i = 0; i < n; i++)
        {
            if(visited[i])
            {
                for(j = 0; j < n; j++)
                {
                    if(!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if(u != -1 && v != -1)
        {
            printf("%d - %d : %d\n", u, v, min);
            minCost += min;
            visited[v] = 1;
            edge++;
        }
    }

    printf("\nMinimum Cost of Spanning Tree = %d\n", minCost);

    return 0;
}
