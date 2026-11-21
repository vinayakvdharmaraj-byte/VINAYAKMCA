#include <stdio.h>

int parent[10];

int find(int i)
{
    while (parent[i] != i)
        i = parent[i];

    return i;
}

void union_set(int i, int j)
{
    int a = find(i);
    int b = find(j);

    parent[a] = b;
}

int main()
{
    int n, e, i, j;
    int u, v, w, min;
    int cost[10][10];
    int mincost = 0, edges = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    for (i = 0; i < n; i++)
        parent[i] = i;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while (edges < n - 1)
    {
        min = 999;

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        if (min == 999)
            break;

        i = find(u);
        j = find(v);

        if (i != j)
        {
            printf("%d - %d : %d\n", u, v, min);

            mincost += min;
            union_set(i, j);
            edges++;
        }

        cost[u][v] = 999;
        cost[v][u] = 999;
    }

    if (edges != n - 1)
        printf("Graph is not connected\n");
    else
        printf("\nMinimum cost = %d\n", mincost);

    return 0;
}

