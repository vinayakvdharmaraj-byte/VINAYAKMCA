#include <stdio.h>

int graph[20][20], transpose[20][20];
int visited[20], stack[20];
int top = -1, n;

void dfs1(int v)
{
    int i;
    visited[v] = 1;

    for (i = 0; i < n; i++)
    {
        if (graph[v][i] == 1 && !visited[i])
            dfs1(i);
    }

    stack[++top] = v;
}

void dfs2(int v)
{
    int i;
    visited[v] = 1;

    printf("%d ", v);

    for (i = 0; i < n; i++)
    {
        if (transpose[v][i] == 1 && !visited[i])
            dfs2(i);
    }
}

int main()
{
    int i, j, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
            transpose[j][i] = graph[i][j];
        }
    }

    // First DFS
    for (i = 0; i < n; i++)
        visited[i] = 0;

    for (i = 0; i < n; i++)
    {
        if (!visited[i])
            dfs1(i);
    }

    // Second DFS
    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nStrongly Connected Components:\n");

    while (top != -1)
    {
        v = stack[top--];

        if (!visited[v])
        {
            dfs2(v);
            printf("\n");
        }
    }

    return 0;
}

