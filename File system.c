
#include <stdio.h>
#include <string.h>

#define MAX 20

int adj[MAX][MAX];
int visited[MAX];
int n;
char names[MAX][50];
int found;

// Breadth First Search
void BFS(int start, char target[])
{
    int queue[MAX];
    int front = 0, rear = 0;
    int i;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;
    found = 0;

    printf("\nBFS Traversal: ");

    while (front < rear)
    {
        int current = queue[front++];

        printf("%s ", names[current]);

        if (strcmp(names[current], target) == 0)
            found = 1;

        for (i = 0; i < n; i++)
        {
            if (adj[current][i] == 1 && visited[i] == 0)
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }

    if (found)
        printf("\nFile found using BFS.\n");
    else
        printf("\nFile not found using BFS.\n");
}

// Depth First Search
void DFS(int vertex, char target[])
{
    int i;

    visited[vertex] = 1;

    printf("%s ", names[vertex]);

    if (strcmp(names[vertex], target) == 0)
        found = 1;

    for (i = 0; i < n; i++)
    {
        if (adj[vertex][i] == 1 && visited[i] == 0)
        {
            DFS(i, target);
        }
    }
}

int main()
{
    int edges, u, v, start, i, j;
    char target[50];

    printf("FILE SYSTEM REPRESENTATION\n");

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Invalid number of nodes.\n");
        return 1;
    }

    printf("\nEnter file/directory names:\n");

    for (i = 0; i < n; i++)
    {
        printf("Node %d: ", i);
        scanf("%49s", names[i]);
    }

    // Initialize adjacency matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            adj[i][j] = 0;
    }

    printf("\nEnter number of connections: ");
    scanf("%d", &edges);

    if (edges < 0 || edges > n * (n - 1) / 2)
    {
        printf("Invalid number of connections.\n");
        return 1;
    }

    printf("\nEnter connections using node numbers:\n");

    for (i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);

        if (u < 0 || u >= n || v < 0 || v >= n || u == v)
        {
            printf("Invalid connection.\n");
            return 1;
        }

        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    printf("\nEnter starting node number: ");
    scanf("%d", &start);

    if (start < 0 || start >= n)
    {
        printf("Invalid starting node.\n");
        return 1;
    }

    printf("Enter file to search: ");
    scanf("%49s", target);

    // Display adjacency matrix
    printf("\nAdjacency Matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", adj[i][j]);

        printf("\n");
    }

    // Perform BFS
    BFS(start, target);

    // Perform DFS
    for (i = 0; i < n; i++)
        visited[i] = 0;

    found = 0;

    printf("\nDFS Traversal: ");
    DFS(start, target);

    if (found)
        printf("\nFile found using DFS.\n");
    else
        printf("\nFile not found using DFS.\n");

    return 0;
}
