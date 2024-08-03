/*
Find the N-th term

You want to get tutelage under the Ultimate Ninja Ankush, but for that you have to pass his test. 
His test is simple: he has given you a relation function, F(n) = 2*F(n-1) + 3*F(n-2),where F(0) = F(1) = 1 and wants you to 
find the ‘N’th term for the function.
The 'N'th term can be very large, return it after modulus 10^9 + 7.

For example:
Given ‘N’ = 3,
F(3) = 13,This is because F(0) = 1, F(1) = 1, Therefore F(2) = 2*F(1) + 3*F(1), therefore F(2) = 5, and F(3) = 2*F(2) + 3*F(1), therefore F(3) = 13.

Input format:
The first line of input contains an integer ‘T’ denoting the number of test cases.

The next ‘T’ lines contains a single integer ‘N’, which denotes the number given to us.

Output Format :
For each test case, You are supposed to return the Nth term for the given relation.

Note:
You are not required to print the expected output; it has already been taken care of. Just implement the function.

Constraints:
1 <= ‘T’ <= 10
1 <= ‘N’ <= 10 ^ 9

Time Limit: 1sec.

Sample Input 1 :
2
3
4
Sample Output 1 :
13
41  
Explanation of the Sample Input 1:
In the first test case,F(3) = 13,This is because F(0) = 1, F(1) = 1, Therefore F(2) = 2*F(1) + 3*F(1), therefore F(2) = 5, and F(3) = 2*F(2) + 3*F(1), therefore F(3) = 13.

In the second test case, F(4) = 41, This is because F(2) = 5, F(3) = 13, F(4) = 2*F(3) + 3*F(2), therefore F(4) = 41.   
Sample Input 2 :
2
5
2
Sample Output 2 :
121
5
*/



// have used transition matrix principle here : first read about generating the transition matrix for any recurrence relation
// from hand notes and then look at code
#define ll long long

const int mod = 1e9+7;

void matrix_product(vector<vector<ll>> &a, vector<vector<ll>> &b, int n){
	vector<vector<ll>> temp(n, vector<ll>(n, 0));

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			for(int k=0; k<n; k++){
				ll add = (a[i][k] * b[k][j]) % mod;
				temp[i][j] = (temp[i][j] + add) % mod;
			}
		}
	}

	for(int i=0; i<n; i++){
			for (int j = 0; j < n; j++) {
				b[i][j] = temp[i][j];
			}
	}
}

long long int nthTerm(long long int n) {
	vector<vector<ll>> t{{2,3}, {1,0}};
	vector<vector<ll>> res{{1,0}, {0,1}};

	ll power = n-1;
	while(power > 0){
		if(power % 2 == 1){
			matrix_product(t, res, 2);
			power--;
		}

		if(power > 0){
			matrix_product(t,t,2);
			power /= 2;
		}
	}

	return (res[0][0] + res[0][1]) % mod;
}