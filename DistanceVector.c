#include <stdio.h>
#include <string.h>

int main()
{
    int i, j, x, y, n, d, delay = 1000, d_node = -1;
    int edge[50][50], c[50], cost[50][50];
    char ch;

    printf("\nEnter the No. of nodes in the graph: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            printf("\nIs there any edge from %d to %d? (1/0): ", i + 1, j + 1);
            scanf("%d", &d);
            edge[i][j] = d;
            edge[j][i] = d;
        }
    }

    printf("\nEnter the source and destination nodes: ");
    scanf("%d %d", &x, &y);

    for (i = 0; i < n; i++)
    {
        if (edge[i][x - 1] || edge[x - 1][i])
        {
            printf("\nEnter the cost of node %d to its neighbor %d: ", x, i + 1);
            scanf("%d", &c[i]);
            printf("\nEnter the routing table entry from %d to %d: ", i + 1, y);
            scanf("%d", &cost[i][y - 1]);
            if (delay > (c[i] + cost[i][y - 1]))
            {
                d_node = i + 1;
                delay = c[i] + cost[i][y - 1];
            }
        }
    }

    if (d_node != -1)
    {
        printf("\nEstimated cost from node %d to %d is %d via the node %d.\n", x, y, delay, d_node);
    }
    else
    {
        printf("\nNo valid route found from node %d to %d.\n", x, y);
    }

    return 0;
}
