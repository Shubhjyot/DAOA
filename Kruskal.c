#include<stdio.h>
#include<stdlib.h>

#define MAX 9
#define INF 999

int parent[MAX];
int find(int i);
int unionsets(int i,int j);

int main(){
    int i,j,n,ne=1;
    int min, mincost=0;
    int cost[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    printf("\nEnter Adjacency Matrix: ");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
            cost[i][j]=INF;
        }
    }

    printf("The Edges of Minimum Cost Spanning Tree: \n");
    while(ne<n){
        int u=-1,v=-1;
        min=INF;

        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(cost[i][j]<min){
                    min=cost[i][j];
                    u=i;
                    v=j;
                }
            }
        }

        int set_u=find(u);
        int set_v=find(v);

        if(unionsets(set_u,set_v)){
            printf("Edge %d: (%d,%d) %d\n",ne++,u,v,min);
            mincost+=min;
        }

        cost[u][v]=cost[v][u]=INF;
    }
    printf("\nMinimum cost: %d\n",mincost);
    return 0;
}

int find(int i){
    while(parent[i])
    i=parent[i];
    return i;
}

int unionsets(int i,int j){
    if(i!=j){
        parent[j]=i;
        return 1;
    }
    else 0;
}
