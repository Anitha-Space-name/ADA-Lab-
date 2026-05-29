#include <stdio.h>

#define MAX 20

struct Edge
{
    int u, v, w;
};

int parent[MAX];

int find(int i)
{
    while(parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int i, int j)
{
    parent[j] = i;
}

int main()
{
    int n, e, i, j;
    struct Edge edges[MAX], temp;
    int minCost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v weight):\n");
    for(i = 0; i < e; i++)
    {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    for(i = 0; i < e - 1; i++)
    {
        for(j = 0; j < e - i - 1; j++)
        {
            if(edges[j].w > edges[j + 1].w)
            {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    for(i = 0; i < n; i++)
        parent[i] = i;

    printf("\nEdges in MST:\n");

    for(i = 0; i < e; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;

        int set_u = find(u);
        int set_v = find(v);

        if(set_u != set_v)
        {
            printf("%d - %d : %d\n", u, v, edges[i].w);
            minCost += edges[i].w;
            unionSet(set_u, set_v);
        }
    }

    printf("\nMinimum Cost of Spanning Tree = %d\n", minCost);

    return 0;
}
