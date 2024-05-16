#include<stdio.h>
#include<limits.h>

void printSolution(int coins[],int dp[],int amount,int numCoins){
    printf("Denominations Required: \n");
    int i=amount;
    while(i>0 && dp[i]>0){
        for(int j=0;j<numCoins;j++){
            if(i-coins[j]>=0 && dp[i]==1+dp[i-coins[j]]){
                printf("%d ",coins[j]);
                i-=coins[j];
                break;
            }
        }
    }
    printf("\nNumber of coins required: %d",dp[amount]);
}

int count(int coins[],int numCoins, int amount){
    int dp[amount+1];
    dp[0]=0;
    for(int i=1;i<=amount;i++){
        dp[i]=INT_MAX;
    }
    for(int i=1;i<=amount;i++){
        for(int j=0;j<numCoins;j++){
            if(coins[j]<=i){
                dp[i]=(dp[i]<1+dp[i-coins[j]]) ? dp[i]:1+dp[i-coins[j]];
            }
        }
    }
    printSolution(coins,dp,amount,numCoins);
    return dp[amount];
}

int main(){
    int numCoins;
    printf("Enter the no. of  denominations:\n");
    scanf("%d",&numCoins);
    int coins[numCoins];
    printf("Enter the denominations:\n");
    for(int i=0;i<numCoins;i++){
        scanf("%d",&coins[i]);
    }
    int amount;
    printf("Enter the amount to be made: ");
    scanf("%d",&amount);

    int result=count(coins,numCoins,amount);
    return 0;
}