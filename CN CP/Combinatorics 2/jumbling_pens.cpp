/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575414/offering/8882758/problem/19132
*/


// ans = n! / (red! * green! * blue!)
#define ll long long

const ll mod = 1e9 + 7;
bool factDone = false;

ll fact[20000];

ll mod_pow(ll a, ll b) {
    ll res = 1;

    while(b){
        if(b&1) res = (res*a)%mod;

        a = (a*a)%mod;
        b /= 2;
    }

    return res;
}

int jumbledPens(int n, int red, int green, int blue)
{
	if(!factDone) {
		fact[0] = 1;
		for(int i=1; i<20000; i++) fact[i] = (fact[i-1] * i) % mod;
        factDone = true;
	}

	ll temp = (((fact[red] * fact[green]) % mod) * fact[blue]) % mod;  // important and dont forget to do mod after each multiplication, since overflow can occur if we miss any 1 intermediate mod
	ll ans = (fact[n] * mod_pow(temp, mod-2)) % mod;

	return (int)(ans);
}