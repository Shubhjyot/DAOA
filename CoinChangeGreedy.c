#include <stdio.h>

void CoinChange(int coins[],int n,int amount){
    int i=n-1;
    printf("Coins used: \n");
    while(amount>0 && i>=0){
        while(amount>=coins[i]){
            printf("%d",coins[i]);
            amount-=coins[i];
        }
        i--;
    }
    if(amount>0){
        printf("\nChange cannot be given for the remaining amount: %d\n", amount);
    } else{
        printf("\n");
    }
}

int main(){
    int n;
    printf("Enter number of coin denominations: ");
    scanf("%d",&n);
    int coins[n];
    printf("Enter the coin denominations in descending order:\n ");
    for(int i=0;i<n;i++){
        scanf("%d",&coins[i]);
    }
    int amount;
    printf("Enter the amount for which the change needs to be made: ");
    scanf("%d", &amount);

    printf("Minimum coins needed to make %d:\n", amount);
    CoinChange(coins, n, amount);

    return 0;
}