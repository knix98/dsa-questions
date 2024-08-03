/*
Find Prime Numbers

You are given a positive integer ‘N’. Your task is to print all prime numbers less than or equal to N.
Note: A prime number is a natural number that is divisible only by 1 and itself. Example - 2, 3, 17, etc.
You can assume that the value of N will always be greater than 1. So, the answer will always exist.
Input Format:
The input contains a single positive integer ‘N’.


Output Format :
Print single space-separated prime numbers less than or equal to ‘N’ in increasing order.

Note :
You do not need to print anything; it has already been taken care of. Just implement the function.
Constraints:
2 <= N <= 10^7

Where ‘N’ is the given positive integer.

Time Limit: 1sec
Sample Input 1 :
7
Sample Output 1 :
2 3 5 7
Sample Output 1 Explanation:
For the given input, all prime numbers from 2 to 7 are 2, 3, 5 and 7.
Sample Input 2 :
30
Sample Output 2 :
2 3 5 7 11 13 17 19 23 29
*/




/*SIEVE OF ERATOSTHENES -> for visual explanation, refer CN CP PDF notes of number theory 1*/
// Time : O(n*loglogn)
// regarding time complexity explanation is regarding CN CP my notes

vector<int> primeNumbersTillN(int n) 
{ 
	vector<int> primes;

    vector<int> isPrime(n+1, 1); // initially marking every number as prime

	isPrime[0] = isPrime[1] = 0;  // 0 and 1 is not prime

	long long i=2;
	while(i <= n){
		if(isPrime[i]){
			primes.push_back(i);

			for(long long j=i*i; j<=n; j+=i){  // cancel out all multiples of this prime number (i) starting from i*i as non-prime
				isPrime[j] = 0;                // starting from (i*i), because i*2, i*3, i*4 ...  would have been crossed out already earlier in previous iterations with i = 2,3,5...
			}                                  // and we only need to go max till i=sqrt(n), since after that i*i > n (out of range), so auto maticall the inner for loop wont run
		}

		i++;
	}

	return primes;
}