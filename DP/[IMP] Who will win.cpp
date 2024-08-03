/*
Whis and Beerus are playing a new game today.
They form a tower of N coins and make a move in alternate turns.
Beerus plays first. In one step, the player can remove either 1, X, or Y coins from the tower.
The person to make the last move wins the game. Can you find out who wins the game?

Input format :
The first and the only line of input contains three integer values separated by a single space. They denote the value of N, X and Y, respectively.
Output format :
Prints the name of the winner, either 'Whis' or 'Beerus' (Without the quotes).
Constraints :
1 <= N <= 10 ^ 6
2 <= X <= Y<= 50

Time Limit: 1 sec
*/

string findWinner(int n, int x, int y)
{
    // dp[i] = who will win if there are i coins
    // dp[i] == 1 signifies that the person taking the 1st chance wins,
    // dp[i] == 2 signifies that the person taking the 2nd chance wins,
    int *dp = new int[n + 1]{0};
    dp[0] = 2; // because the person who has removed all coins has won already
    dp[1] = 1; // obviously

    for (int i = 2; i <= n; i++)
    {
        if (i - x >= 0 && dp[i - x] == 2)
        {
            // if it's possible to remove x coins and after removing x coins, i will win...
            dp[i] = 1;
        }
        else if (i - y >= 0 && dp[i - y] == 2)
        {
            dp[i] = 1;
        }
        else if (dp[i - 1] == 2)
        {
            dp[i] = 1;
        }
        else
        {
            // if none of the above conditions satisfied...that means i can't win from this situation.
            dp[i] = 2;
        }
    }

    int ans = dp[n];
    delete[] dp;

    if (ans == 1)
    {
        return "Beerus";
    }
    else
    {
        return "Whis";
    }
}