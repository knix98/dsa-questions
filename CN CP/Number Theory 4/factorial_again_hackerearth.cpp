/*
Kate has finally calmed down and decides to forgive Little Deepu, but she won't forgive him just like that. 
She agrees to forgive him on the grounds that he can solve a mathematical question for her.
She gives Deepu a large number N and a prime number P and asks him to calculate ((3*N)! / (3!^N) )%P.
Your task is to help Little Deepu get back together with Kate.

Input
First line contains number of test cases T.
Next T lines contain two integers N and P, where P is a prime.

Output
For each test case output the result ( (3*N)! / (3!)N ) % P.

Constraints:
1 ≤ T ≤ 10000
1 ≤ N ≤ 333333333
1 ≤ P ≤ 1000000000
1 ≤ abs(3*N-P) ≤ 1000

Input : 
2
3 11
2 11

Output :
8
9
*/




#include<bits/stdc++.h>

using namespace std;

#define ll  long long int
ll  mod_power(ll  b, ll  p, ll  m){
	ll  r=1;
	b%=m;
	while(p>0){
		if(p&1){
			r = r * b % m;
		}
		b= b * b % m;
		p>>=1;
	}
	return r;
}

ll  factorialAgain(ll  n, ll  p)
{
	if(3*n >= p) return 0;

	ll ans = p-1;
	for(ll i = 3*n + 1; i<=p-1; i++){
		ll mod_inv = mod_power(i, p-2, p);
		ans = (ans * mod_inv) % p;
	}

	ll mod_inv_of_six = mod_power(6, p-2, p);
	ll den_inv = mod_power(mod_inv_of_six, n, p);

	return (ans * den_inv) % p;
}

int main(){
	int t;
	cin >> t;

	vector<ll> answers;
	while(t--){
		ll n, p;
		cin >> n >> p;

		answers.push_back(factorialAgain(n,p));
	}

	for(auto i : answers) cout << i << endl;
}