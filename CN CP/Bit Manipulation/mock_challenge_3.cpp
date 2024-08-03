/*
Ninja And The Task

Ninja has been assigned one task by his teacher; as he is a lazy student, he doesn't want to solve it. You are Ninja's best friend, and he asked you to solve the below task assigned to him.
Given an integer 'X' your task is to count the number of integer values 'Y' such that ('X' ^ 'Y') > 'X' and 0 < 'Y' < 'X'.
Where ( ^ ) is the bitwise xor operator.
EXAMPLE:
Input: 'X' = 2
Output: 1

There is only one value of 'Y' = 1 satisfies the condition ('X' ^ 'Y') > 'X' and 0 < 'Y' < 'X'
Input Format :
The first line of input contains an integer 'T', denoting the number of test cases. 

For each test case, there will be only one integer 'X' on a separate line.
Output format :
For each test case, print the number of possible values of 'Y' such that ('X' ^ 'Y') > 'X' and 0 < 'Y' < 'X' satisfies.
Note :
You don't need to print anything. It has already been taken care of. Just implement the given function.
Constraints :
1 <= 'T' <= 10^2
1 <= 'X' <= 10^10

Time Limit: 1 sec
Sample Input 1 :
2
2
10
Sample Output 1 :
1
5
Explanation Of Sample Input 1 :
For the first test case, there is only one value of 'Y' = 1 satisfies the condition ('X' ^ 'Y') > 'X' and 0 < 'Y' < 'X'.

For the first test case, there are following five values of 'Y' = 1 satisfies the condition ('X' ^ 'Y') > 'X' and 0 < 'Y' < 'X'.
1, 4, 5, 6, 7
Sample Input 2 :
2
5
100
Sample Output 2 :
2
27
*/



// APPROACH : written in mock challenge 3 CN CP notes
#define ll long long
long long countValues(long long x) {
    int lastSetBitPosition = 0; // signifies last set bit position in X

    ll checker = 1;
    for(int i=0; i<63; i++){  // getting last set bit position in X
        if(x & (checker<<i)) lastSetBitPosition = i;
    }

    ll ans = 0;  
    for(int i=lastSetBitPosition-1; i>=0; i--){  // checking the unset bit positions of x for getting corresponding Y values (Y values having MSB at this position)
        if((x & (checker<<i)) == 0) ans += (checker<<i);
    }

    return ans;
}