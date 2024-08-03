/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575414/offering/8882758/problem/19133
*/


// see how inclusion-exclusion principle is implemented in code
#define ll long long

ll GCD(ll a, ll b){
	ll temp;
	while(b){
		temp = a%b;
		a = b;
		b = temp;
	}

	return a;
}

ll LCM(ll a, ll b){
	return (a*b) / GCD(a,b);
}

int includedElements(int n, vector<int> &set)
{
	int N = set.size();

	int ans = 0;
	for(ll i=1; i < (1<<N); i++) {  // be careful in this step of generating subsets => need to go from 1 to 2^N - 1
		ll lcm = 1, count = 0; // lcm for keep on calculating the lcm of all the numbers present in the current set
                               // count for keeping a count of the numbers present in the current set
		
		for(ll j=0; j<N; j++){
			if(i & (1<<j)) {
				count++;
				lcm = LCM(lcm, set[j]);
			}
		}

		if(count & 1) ans += (n/lcm); 
		else ans -= (n/lcm);
	}

    // ans would contain the count of nums which are divisible by the given set of numbers
    // so we have to return n-ans
	return n - ans;
}