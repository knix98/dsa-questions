/*
Sanchit And Nuclear Reactor

We all know Sanchit Lee Cooper who is a Caltech theoretical physicist. He has eccentric and arrogant behavior. 
Due to his belief that he's intellectually superior, he's not ashamed to insult his own friends, like Howard, 
who is an engineer and not a real scientist. But nobody messes with an engineer. So Howard accepted an challenge from Sanchit. 
Sanchit was involved in numerous experiments as a wunderkind, such as his plan for building his own 
nuclear reactor - a plan stopped by government. So Sanchit presented Howard with a problem about his own nuclear reactor. 
It contains a large tank and at each second an atom is introduced in the tank which reacts with already existing atoms and 
produces some energy. Also he defined a special threshold number for his reactor called Cooper number m which is always a prime number. 
Energy output is defined as previous energy output of the tank multiplied by number of atoms present in it. But due to some 
special condition of the tank, all atoms attains stable state (net charge becomes 0) when number of atoms are multiple of 
Cooper number and no new reaction occurs. Energy output in this case is same as previous case. Also initial energy of the 
reactor is 1 and initially there is no atom in the tank. Now Sanchit ask Howard to tell the energy output after time T. 
But sadly Howard is not able to solve it and ask for your help.

Input Format
The first line of input contains T(number of the test case), each test case follows as.
contian two space-separated integers N and M where M is a prime number.
Output Format
You have to determine the energy output after time T. As the number can be quite large so output it modulo Cooper number m.

Constraints:
1 <= T <= 100
1 <= N <= 10^18
1 <= M <= 10^4

Sample Input
2
1 5
2 5
Sample Output
1
2
Explanation
After 1 seconds, there is only 1 atom in the tank. Hence energy output is 1. After 2 seconds, there are 2 atoms which reacts to give energy output of 2.
*/


// idea is written in Hand CN CP notes
// this is the first approach which I coded myself... in this I calculated [(p-1)^n] % p , manually using modular_exponentiation
// But this can be calulated in 1 line only using the concept written in notes, and that modified code is coded in 2nd code below
#include<bits/stdc++.h>
using namespace std;

#define ll long long

// this func would calculate (a^b)%m
ll powerModuloFunc(ll a, ll b, ll m){
    ll ans = 1;
    while(b > 0){
        if(b%2 == 1){
            ans = ((ans%m) * (a%m)) % m;
            b--;
        }

        if(b > 0){
            a = ((a%m) * (a%m)) % m;
            b /= 2;
        }
    }

    return ans;
}

int main(){
    int t;
    cin >> t;

    vector<int> answers;
    while(t--){
        ll n, m;
        cin >> n >> m;

        if(m == 1){
            answers.push_back(1);
            continue;
        }

        ll modOfProductTillM = 1;
        ll lastNumberToMultiply = n < m ? n : m-1;
        for(ll i=2; i<=lastNumberToMultiply; i++){
            modOfProductTillM = (modOfProductTillM * i) % m;
        }

        if(n<=m){
            answers.push_back(modOfProductTillM);
            continue;
        }

        ll powerOfModOfProductTillM = n / m;
        ll numberOfExtraNumsToMultiply = n % m;

        ll ans = powerModuloFunc(modOfProductTillM, powerOfModOfProductTillM, m);

        for(ll i=1; i<=numberOfExtraNumsToMultiply; i++){
            ans = (ans * i) % m;
        }

        answers.push_back(ans);
    }

    for(auto i : answers) cout << i << endl;

    return 0;
}

// more efficient approach...
int main(){
    int t;
    cin >> t;

    vector<int> answers;
    while(t--){
        ll n, m;
        cin >> n >> m;

        if(m == 1){
            answers.push_back(1);
            continue;
        }

        ll powerOfModOfProductTillM = n / m;
        ll numberOfExtraNumsToMultiply = n % m;

        ll ans = powerOfModOfProductTillM & 1 ? m-1 : 1;

        for(ll i=1; i<=numberOfExtraNumsToMultiply; i++){
            ans = (ans * i) % m;
        }

        answers.push_back(ans);
    }

    for(auto i : answers) cout << i << endl;

    return 0;
}