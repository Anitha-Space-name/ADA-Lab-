#include <stdio.h>

#define MAX 10

struct Graph
{
    int adj[MAX][MAX];
    int indegree[MAX];
    int vertices;
};

int main()
{
    struct Graph g;
    int i, j, k;
    int count = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &g.vertices);

    printf("Enter adjacency matrix:\n");

    for(i = 0; i < g.vertices; i++)
    {
        for(j = 0; j < g.vertices; j++)
        {
            scanf("%d", &g.adj[i][j]);
        }
    }

    for(i = 0; i < g.vertices; i++)
    {
        g.indegree[i] = 0;
    }

    for(i = 0; i < g.vertices; i++)
    {
        for(j = 0; j < g.vertices; j++)
        {
            if(g.adj[i][j] == 1)
            {
                g.indegree[j]++;
            }
        }
    }

    printf("\nTopological Ordering: ");

    while(count < g.vertices)
    {
        for(i = 0; i < g.vertices; i++)
        {
            if(g.indegree[i] == 0)
            {
                printf("%d ", i);

                g.indegree[i] = -1;

                for(j = 0; j < g.vertices; j++)
                {
                    if(g.adj[i][j] == 1)
                    {
                        g.indegree[j]--;
                    }
                }

                count++;
            }
        }
    }

    return 0;
}
