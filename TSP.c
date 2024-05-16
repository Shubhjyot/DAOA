#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min(int x, int y) {
    return (x < y) ? x : y;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permute(int **graph, int *path, int start, int end, int *min_path, int *min_path_arr) {
    if (start == end) {
        int current_path_length = 0;
        for (int i = 0; i < end; i++) {
            current_path_length += graph[path[i]][path[i + 1]];
        }
        current_path_length += graph[path[end]][path[0]];
        if (current_path_length < *min_path) {
            *min_path = current_path_length;
            for (int i = 0; i <= end; i++) {
                min_path_arr[i] = path[i];
            }
        }
    } else {
        for (int i = start; i <= end; i++) {
            swap((path + start), (path + i));
            permute(graph, path, start + 1, end, min_path, min_path_arr);
            swap((path + start), (path + i));
        }
    }
}

void TSP(int **graph, int V) {
    int path[V];
    int min_path = INT_MAX;
    int min_path_arr[V];
    
    for (int i = 0; i < V; i++) {
        path[i] = i;
    }
    
    permute(graph, path, 0, V - 1, &min_path, min_path_arr);
    
    printf("Minimum path length: %d\n", min_path);
    printf("Minimum path: ");
    for (int i = 0; i < V; i++) {
        printf("%d ", min_path_arr[i]);
    }
    printf("%d\n", min_path_arr[0]); // Return to the starting city
}

int main() {
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    
    int **graph = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        graph[i] = (int *)malloc(V * sizeof(int));
        printf("Enter the adjacency matrix for vertex %d: ", i);
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    TSP(graph, V);
    
    for (int i = 0; i < V; i++) {
        free(graph[i]);
    }
    free(graph);
    
    return 0;
}
