#include <stdio.h>
#include <stdlib.h>

#define MAX_JOBS 50

struct Job{
    int id;
    int deadline;
    int Profit;
};

int compareJobs(const void* a,const void* b){
    return((struct Job*)b)->Profit-((struct Job*)a)->Profit;
}

void scheduleJobs(struct Job jobs[],int n){
    qsort(jobs,n,sizeof(struct Job),compareJobs);

    int slot[n];
    for(int i=0;i<n;i++){
        slot[i]=-1;
    }

    for(int i=0;i<n;i++){
        for(int j=jobs[i].deadline-1;j>=0;j++){
            if(slot[j]==-1){
                slot[j]=i;
                break;
            }
        }
    }

    int totalProfit=0;
    printf("Scheduled Jobs ID and Profit: \n");
    for(int i=0;i<n;i++){
        if(slot[i]!=-1){
            printf("%d %d\n",jobs[slot[i]].id,jobs[slot[i]].Profit);
            totalProfit+=jobs[slot[i]].Profit;
        }
    }
    printf("\nTotal Profit: %d",totalProfit);
}

int main(){
        int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    struct Job *jobs = (struct Job*)malloc(n * sizeof(struct Job));
    if (jobs == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter job details (ID Deadline Profit):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &jobs[i].id, &jobs[i].deadline, &jobs[i].Profit);
    }

    scheduleJobs(jobs, n);
    free(jobs);
    return 0;
}
