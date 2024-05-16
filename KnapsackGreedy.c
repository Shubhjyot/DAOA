#include <stdio.h>
#define MAX 100

void knapsack(int n,int capacity,int weights[],int values[]){
    float ratio[MAX];
    int i,j;
    int tempWeight,tempValue;
    float tempRatio;

    for(i=0;i<n;i++){
        ratio[i]=(float)values[i]/weights[i];
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(ratio[j]<ratio[j+1]){
                tempRatio=ratio[j];
                ratio[j]=ratio[j+1];
                ratio[j+1]=tempRatio;

                tempWeight=weights[j];
                weights[j]=weights[j+1];
                weights[j+1]=tempWeight;

                tempValue=values[j];
                values[j]=values[j+1];
                values[j+1]=tempValue;
            }
        }
    }

    int currentWeight=0;
    float finalValue=0.0;

    for(i=0;i<n;i++){
        if(currentWeight+weights[i]<=capacity){
            currentWeight+=weights[i];
            finalValue+=values[i];
        }
        else{
            int remain=capacity-currentWeight;
            finalValue+=values[i]*((float)remain/weights[i]);
            break;
        }
    }
    printf("\nMaximum Value in Knapsack=%.2f",finalValue);
}

int main(){
    int n,capacity;
    int weights[MAX],values[MAX];
    printf("Enter the number of items:\n");
    scanf("%d",&n);
    printf("Enter Weight and Value for each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d:\n", i + 1);
        printf("Weight: ");
        scanf("%d", &weights[i]);
        printf("Value: ");
        scanf("%d", &values[i]);
    }

    printf("Enter capacity of Knapsack: ");
    scanf("%d",&capacity);
    knapsack(n,capacity,weights,values);
}