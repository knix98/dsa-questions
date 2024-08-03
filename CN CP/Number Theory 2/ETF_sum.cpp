/*
Euler Totient Function Sum

You are given a positive integer ‘N’, your task is to return an array/list of integers such that the sum of Euler Totient Function values of each integer of the array is equal to ‘N’.
Euler Totient Function:
In number theory, Euler's totient function counts the positive integers up to a given integer ‘N’ that is relatively prime to ‘N’.

For Example:
For ‘N’ = 10, if we take the array as 1, 2, 5, 10,
The Euler totient function value of 1 is 1.
The Euler totient function value of 2 is 1.
The Euler totient function value of 5 is 4.
The Euler totient function value of 10 is 4.
So, the summation will be 1 + 1 + 4 + 4 = 10.
Hence this is a valid array for ‘N’ = 10.

Input Format:
The first line contains a single integer ‘T’, representing the number of test cases.

The first line of each test case contains a single integer ‘N’, representing the sum of the Euler Totient Function values of all the elements of the output array.
Output Format:
For each test case, Return all the elements of the array satisfying the condition given in the problem statement.

 If there are multiple answers possible print any one of them.

Output for each test case will be printed in a separate line.
Note
You are not required to print anything; it has already been taken care of. Just implement the function.
Constraints:
1 <= T <= 100
1 <= N <= 10^3

Time Limit: 1 sec.
*/



// based on simple property about ETF (or phi) written in CN CP notes
vector<int> eulerTotientFunction(int n){
    // just find all the divisors of n and return that (DIVISOR SUM PROPERTY)

    vector<int>divisors;

    for(int i=1; i*i <= n ; i++){
        if(n%i == 0){ // means i is a divisor of n
            divisors.push_back(i);
            if(n/i != i) divisors.push_back(n/i); // dont push i, 2 times, in case of : i*i == n
        }
    }

    return divisors;
} 