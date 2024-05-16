#include <stdio.h>

int coinChange(int coins[], int n, int amount) {
    // Create a table to store the minimum number of coins needed for each amount from 0 to amount
    int dp[amount + 1];
    // Initialize the table with a value greater than the amount (indicating impossible to make change)
    for (int i = 0; i <= amount; i++) {
        dp[i] = amount + 1;
    }
    // Base case: 0 coins are needed to make change for amount 0
    dp[0] = 0;
    
    // Iterate through each coin denomination
    for (int i = 0; i < n; i++) {
        // For each coin denomination, update the minimum number of coins needed for each amount
        for (int j = coins[i]; j <= amount; j++) {
            dp[j] = dp[j] < dp[j - coins[i]] + 1 ? dp[j] : dp[j - coins[i]] + 1;
        }
    }
    // If dp[amount] is still greater than amount, it means it's impossible to make change for the given amount
    return dp[amount] > amount ? -1 : dp[amount];
}

int main() {
    int coins[] = {1, 2, 5}; // Available coin denominations
    int n = sizeof(coins) / sizeof(coins[0]); // Number of available coin denominations
    int amount;
    
    printf("Enter the amount for which the change needs to be made: ");
    scanf("%d", &amount);
    
    int minCoins = coinChange(coins, n, amount);
    if (minCoins == -1) {
        printf("It is impossible to make change for the amount %d.\n", amount);
    } else {
        printf("Minimum number of coins needed to make change for amount %d: %d\n", amount, minCoins);
    }

    return 0;
}
