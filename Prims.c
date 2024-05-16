#include <stdio.h>

int a, b, u, v, n, i, j, ne = 0;
int visited[10] = {0}, min, mincost = 0, cost[10][10];

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;  // Use a large value to represent no edge
        }
    }

    visited[0] = 1;  // Start from the first node
    printf("\n");

    while (ne < n - 1) {
        min = 999;

        for (i = 0; i < n; i++) {
            if (visited[i]) {
                for (j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }

        if (!visited[b]) {
            printf("Edge %d: (%d, %d) cost: %d\n", ++ne, a + 1, b + 1, min);
            mincost += min;
            visited[b] = 1;
        }
        cost[a][b] = cost[b][a] = 999;
    }

    printf("\nMinimum cost = %d\n", mincost);
    return 0;
}
