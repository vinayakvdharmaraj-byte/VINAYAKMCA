#include <stdio.h>

int main()
{
    int n, cost[10][10], visited[10] = {0};
    int i, j, u, v, min, mincost = 0, edges = 0;

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

    visited[0] = 1;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while (edges < n - 1)
    {
        min = 999;

        for (i = 0; i < n; i++)
        {
            if (visited[i])
            {
                for (j = 0; j < n; j++)
                {
                    if (!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (min == 999)
        {
            printf("Graph is not connected\n");
            return 0;
        }

        printf("%d - %d : %d\n", u, v, min);

        mincost += min;
        visited[v] = 1;
        edges++;
    }

    printf("\nMinimum cost = %d\n", mincost);

    return 0;
}

