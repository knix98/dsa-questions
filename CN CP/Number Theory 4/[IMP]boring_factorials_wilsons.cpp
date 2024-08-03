/*
Boring Factorials

Sameer and Arpit want to overcome their fear of Maths and so they have been recently practising Maths problems a lot. 
Aman, their friend has been helping them out. But as it goes, Sameer and Arpit have got bored with problems involving factorials. 
Reason being, the factorials are too easy to calculate in problems as they only require the residue modulo some prime and that is 
easy to calculate in linear time. So to make things interesting for them, Aman - The Mathemagician, gives them an interesting task. 
He gives them a prime number P and an integer N close to P, and asks them to find N! modulo P. He asks T such queries.

Input Format:
First line contains an integer T, the number of queries asked.
Next T lines contains T queries of the form “N P”. (quotes for clarity)
Output Format:
Output exactly T lines, containing N! modulo P.

Constraints:
1 <= T <= 1000
1 < P <= 2*10^9
1 <= N <= 2*10^9
Abs(N-P) <= 1000

Sample Input:
3
2 5
5 11
21 71
Sample Output:
2
10
6
*/


// notes about fermat little theorem and calculating modular inverse of a number is written in CN CP hand notes in Number theory-4
#include<bits/stdc++.h>
using namespace std;

#define ll long long

// extended euclid algo for returning gcd(a,b) and also storing soln (x,y) for the eqn ax + by = gcd(a,b)
ll extended_euclid(ll a, ll b, ll &x, ll &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }

    ll x1, y1;
    ll gcd = extended_euclid(b, a%b, x1, y1);

    x = y1;
    y = x1 - ((a/b)*y1);

    return gcd;
}

// this func would return the multiplicative modulo inverse of 'a' under modulo 'm'
// NOTE : instead of using extended euclid for : modulo inverse of 'a' under modulo 'm', we can do this simply by calculating :
//  modulo inverse of 'a' under modulo 'm' (iff m is a prime number) = (a^(m-2)) % m  (using fermat's little theorem)
ll moduleInv(ll a, ll m){
    ll x, y;

    ll gcd = extended_euclid(a, m, x, y);

    if(gcd != 1){
        // means modulo inverse of a doesn't exist
        return -1;
    }
    else{
        return ((x%m) + m) % m;  // ensuring only positive result should be returned (because anyways -ve or +ve modulu inverse would behave similarly)
    }
}

int main(){
    int t;
    cin >> t;

    vector<ll> answers;
    while(t--){
        ll n, p;
        cin >> n >> p;

        if(n >= p) {
            // then obviously n! wud also contain p in it, so n! wud be divisible by p
            answers.push_back(0);
            continue;
        }

        ll ans = p-1;
        for(ll i=p-1; i>n; i--){
            ll modulo_inverse_of_i = moduleInv(i, p); // since i <= p-1 and p = prime number, hence gcd(i, p) = 1 always, and hence modulo inverse of i under modulo p would always exist
            ans = (ans * modulo_inverse_of_i) % p; 
        }

        answers.push_back(ans);
    }

    for(auto i : answers) cout << i << endl;

    return 0;
}