#include <stdio.h>

#define MAX 10
#define INF 99999

int main()
{
    int n, i, j, count, min, u, v, src;

    int cost[MAX][MAX], dist[MAX], visited[MAX];

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

    printf("Enter source vertex: ");
    scanf("%d", &src);

    for(i = 0; i < n; i++)
    {
        dist[i] = cost[src][i];
        visited[i] = 0;
    }

    dist[src] = 0;
    visited[src] = 1;
    count = 1;

    while(count < n)
    {
        min = INF;

        for(i = 0; i < n; i++)
        {
            if(dist[i] < min && !visited[i])
            {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        for(v = 0; v < n; v++)
        {
            if(!visited[v] && dist[u] + cost[u][v] < dist[v])
            {
                dist[v] = dist[u] + cost[u][v];
            }
        }

        count++;
    }

    printf("\nShortest distances from source %d:\n", src);

    for(i = 0; i < n; i++)
    {
        printf("To %d = %d\n", i, dist[i]);
    }

    return 0;
}
