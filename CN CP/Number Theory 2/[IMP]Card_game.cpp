/*
Card Game

Vova again tries to play some computer card game.
The rules of deck creation in this game are simple. Vova is given an existing deck of n cards and a magic number k. The order of the cards in the deck is fixed. Each card has a number written on it; number ai is written on the i-th card in the deck.
After receiving the deck and the magic number, Vova removes x (possibly x = 0) cards from the top of the deck, y (possibly y = 0) cards from the bottom of the deck, and the rest of the deck is his new deck (Vova has to leave at least one card in the deck after removing cards). So Vova's new deck actually contains cards x + 1, x + 2, ... n - y - 1, n - y from the original deck.
Vova's new deck is considered valid iff the product of all numbers written on the cards in his new deck is divisible by k. So Vova received a deck (possibly not a valid one) and a number k, and now he wonders, how many ways are there to choose x and y so the deck he will get after removing x cards from the top and y cards from the bottom is valid?

Input
The first line contains two integers n and k (1 ≤ n ≤ 100 000, 1 ≤ k ≤ 10^9).

The second line contains n integers a1, a2, ..., an (1 ≤ ai ≤ 10^9) — the numbers written on the cards.

Output
Print the number of ways to choose x and y so the resulting deck is valid.

Sample Input 1
3 4
6 2 8
Sample Output 1
4

Sample Input 2
3 6
9 1 14
Sample Output 2
1
*/




// Explanation of approach is written in Hand notes . You can understand this code after reading that notes
#include<bits/stdc++.h>
using namespace std;

#define ll long long

// Although this code for doing prime factorisation using sqrt(n) method worked here 
// but dont use this code for sqrt(n) prime factorisation 
// Plz always follow the code written in ETF_using_sqrt(n)_prime_factorisation.cpp for doing sqrt(n) prime factorisation
// because the correct method only takes care of cases where in n contains a prime factor greater than sqrt(n) , or greater than 10^6
void primeFactorisationOfK(vector<pair<ll,ll>> &pfok, ll k){
	for(ll i = 2; i<=k; i++){
		if((k % i) == 0){
			pair<ll,ll> pf(i, 0);

			while((k % i) == 0){
				pf.second++;
				k /= i;
			}

			pfok.push_back(pf);
		}
	}
}

void findPowersTillIndex(vector<ll> &cards, vector<vector<pair<ll,ll>>> &powersTillIndex, vector<pair<ll,ll>> &pfok){
	for(int i=0; i<cards.size(); i++){
		ll card = cards[i];

        // Although this code for doing prime factorisation using sqrt(n) method worked here 
        // but dont use this code for sqrt(n) prime factorisation 
        // Plz always follow the code written in ETF_using_sqrt(n)_prime_factorisation.cpp for doing sqrt(n) prime factorisation
        // because the correct method only takes care of cases where in n contains a prime factor greater than sqrt(n) , or greater than 10^6
		vector<pair<ll,ll>> powersOfCard;
		for(int j=0; j<pfok.size(); j++){
			ll pf = pfok[j].first;

			pair<ll,ll> powerOfThisPf(pf, 0);
			while(card%pf == 0){
				powerOfThisPf.second++;
				card /= pf;
			}

			powersOfCard.push_back(powerOfThisPf);
		}

		if(i > 0){  // then add powers till previous card 
			for(int j=0; j<pfok.size(); j++){
				powersOfCard[j].second += powersTillIndex[i-1][j].second;
			}
		}

		powersTillIndex.push_back(powersOfCard);
	}
}

bool rangeDivisibleByK(vector<vector<pair<ll,ll>>> &powersTillIndex, int i, int mid, vector<pair<ll,ll>> &pfok){
	for(int j=0; j<pfok.size(); j++){
		int powerOfThisPfInRange;
		if(i == 0){
			powerOfThisPfInRange = powersTillIndex[mid][j].second;
		}
		else{
			powerOfThisPfInRange = powersTillIndex[mid][j].second - powersTillIndex[i-1][j].second;
		}

		if(powerOfThisPfInRange < pfok[j].second) return false;
	}

	return true;
}

int main(){
	ll n,k;
	cin >> n >> k;

	vector<ll> cards(n);
	for(int i=0; i<n; i++){
		cin >> cards[i];
	}

	vector<pair<ll,ll>> pfok;
	primeFactorisationOfK(pfok, k);

	vector<vector<pair<ll,ll>>> powersTillIndex;
	findPowersTillIndex(cards, powersTillIndex, pfok);

	ll ans = 0;
	for(int i=0; i<cards.size(); i++){
		// perform binary algo for each card
		int st = i;
		int en = cards.size() - 1;
		int minEnForCurrentI = INT_MAX;
		while(st <= en){
			int mid = (st+en)/2;
			if(rangeDivisibleByK(powersTillIndex, i, mid, pfok)){
				minEnForCurrentI = mid;
				en = mid-1;
			}
			else{
				st = mid+1;
			}
		}

		if(minEnForCurrentI < INT_MAX){
			ans += (cards.size() - minEnForCurrentI);
		}
	}	

	cout << ans << endl;

	return 0;
}