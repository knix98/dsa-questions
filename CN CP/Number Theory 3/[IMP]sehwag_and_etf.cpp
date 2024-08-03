/*
Sehwag and ETF

Sehwag has been solving a lot of mathematical problems recently. 
He was learning ETF (Euler Totient Function) and found the topic quite interesting. So, he tried solving a question on ETF. 
He will be given two numbers L and R. 
He has to find the probability that the ETF of a number in the range [L, R] is divisible by a number K.

Input Format:
The first line contains an integer T, representing the number of test cases.
The next T lines will contain three integers L, R and K.

Constraints:
1 <= T <= 10
1 <= L <= R <= 10^12
0 <= R - L <= 10^5
1 <= K <= 10^6

Output Format:
Print the answer in a new line after rounding off the first 6 digits after the decimal place.

Sample Input 1:
3
1 4 2
2 5 2
3 10 4
Sample Output 1:
0.500000
0.750000
0.375000
*/



// lot of things to learn here, plz revise the whole code
// since L and R can be as large as 10^12, so in order to find the numbers prime factors (for finding ETF of all nums) we can do a sieve of
// that much size. So instead we would use sqrt(n) method of finding all the prime factors of these numbers using segmented sieve method
#include <bits/stdc++.h>
using namespace std;

#define ll long long

// using a pre computation sieve of size (10^6 = sqrt(10^12)) , to precompute all prime numbers till 10^6 and store them in vector<int> primes
vector<int> sieve(1000001, 1);
vector<int> primes;

void sieveForFindingPrimes(){
    sieve[0] = sieve[1] = 0;

    // we need to go all the way till 10^6, so that we can fill all the primes till 10^6 in our primes vector
    for(ll i=2; i <= 1000000; i++){
        if(sieve[i]){
            primes.push_back(i);

            for(ll j = i*i; j<=1000000; j+=i){
                sieve[j] = 0;
            }
        }
    }
}

void findETFs(vector<ll> &phi, vector<ll> &nums, ll l, ll r){
    for(auto prime : primes){
        if(prime > r) break;

        ll baseMultiple; // finding first multiple of current prime withing the range [l, r]
        if(prime >= l) baseMultiple = prime;
        else{
            baseMultiple = (l/prime) * prime;
            if(baseMultiple < l) baseMultiple += prime;
        }

        while(baseMultiple <= r){
            // remove powers of current prime from current multiple (current multiple of current prime)
            while((nums[baseMultiple - l] % prime) == 0){
                nums[baseMultiple - l] /= prime;
            }

            // phi[baseMultiple - l] /= prime;
            // phi[baseMultiple - l] *= (prime-1);
            phi[baseMultiple - l] -= phi[baseMultiple - l] / prime;
            baseMultiple += prime;
        }
    }

    // This is important, since, when we have accounted for all the prime factors of a number
    // till 10^6 , then in the end we need to check whether there is a last prime number still remaining in the prime factorisation of number
    // which is larger than 10^6
    for(int i=0; i<nums.size(); i++){
        if(nums[i] > 1){
            // that means nums[i] has one more prime factor remaining, which is the current value of nums[i] itself
            // phi[i] /= nums[i];
            // phi[i] *= (nums[i]-1);
            phi[i] -= phi[i] / nums[i];
            nums[i] = 1;
        }
    }
}

int main()
{
    sieveForFindingPrimes();

	int t;
    cin >> t;

    vector<double> answers;
    while(t--){
        ll l, r, k;
        cin >> l >> r >> k;

        vector<ll> phi((r-l) + 1); // this vector for storing etf values of all numbers in range
        vector<ll> nums((r-l) + 1); // this vector would be used for prime factorisation of each number in range
                                    // whenever we find a prime factor of current number , then we would need to remove all powers of this prime from current number
                                    // for that division purpose we would use the num[i] value. This is important, since, when we have accounted for all the prime factors of a number
                                    // till 10^6 , then in the end we need to check whether there is a last prime number still remaining in the prime factorisation of number
                                    // which is larger than 10^6
        for (int i = 0; i < phi.size(); i++) {
            phi[i] = i + l;
            nums[i] = i + l;
        }

        findETFs(phi, nums, l, r);

        double totalNums = (r-l) + 1;
        int validNum = 0;

        for(int i=0; i<phi.size(); i++){
            if((phi[i] % k) == 0) validNum++;
        }

        answers.push_back(validNum / totalNums);
    }

    cout << fixed;
    for(auto i : answers) cout << setprecision(6) << i << endl;
}