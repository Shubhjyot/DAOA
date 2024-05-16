#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define INF 99999

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int n, int source){
    int dist[MAX_VERTICES];
    bool visited[MAX_VERTICES]={false};
    int i,j;

    for(i=0;i<n;i++){
        dist[i]=INF;
    }
    dist[source]=0;

    for(i=0;i<n;i++){
        int minDist=INF, minIndex;
        for(j=0;j<n;j++){
            if(!visited[j]&& dist[j]<minDist){
                minDist=dist[j];
                minIndex=j;
            }
        }

        visited[minIndex]=true;

        for(j=0;j<n;j++){
            if(!visited[j] && graph[minIndex][j] && dist[minIndex]!=INF && dist[minIndex]+graph[minIndex][j]<dist[j]){
                dist[j]=dist[minIndex]+graph[minIndex][j];
            }
        }
    }

    printf("Shortest Distances from the Source Vertex:%d\n",source);
    for(i=0;i<n;i++){
        printf("Vertex %d: %d \n",i,dist[i]);
    }
}

int main(){
    int graph[MAX_VERTICES][MAX_VERTICES];
    int n,source;

    printf("Enter the number of vertices:\n");
    scanf("%d",&n);

    printf("Enter the adjacency matrix:(0 for no edge, INF for infinity)\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }

    printf("Enter the source:");
    scanf("%d",&source);
    dijkstra(graph,n,source);
    return 0;
}