#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int, int> m1, m2;
		for(int i = 0; i < basket1.size(); i++) {
			if(m2.find(basket1[i]) != m2.end()) {
				m2[basket1[i]]--;
				if(m2[basket1[i]] == 0) m2.erase(basket1[i]);
			} 
			else m1[basket1[i]]++;
			
			if(m1.find(basket2[i]) != m1.end()) {
				m1[basket2[i]]--;
				if(m1[basket2[i]] == 0) m1.erase(basket2[i]);
			}
			else m2[basket2[i]]++;
		}

		auto i1 = m1.begin();
		while(i1 != m1.end()) {
			if(i1->second % 2) return -1;
			i1->second /= 2;
			advance(i1, 1);
		}

		auto i2 = m2.begin();
		while(i2 != m2.end()) {
			if(i2->second % 2) return -1;
			i2->second /= 2;
			advance(i2, 1);
		}

		cout << "m1 => ";
		for(auto it : m1) cout << it.first << "," << it.second << " ";
		cout << endl;
		cout << "m2 => ";
		for(auto it : m2) cout << it.first << "," << it.second << " ";
		cout << endl;

		long long ans = 0;
		while(m1.size() && m2.size()) {
			if(m1.begin()->first < m2.begin()->first) {
				auto it1 = m1.begin();
				auto it2 = m2.rbegin();
				if(it1->second > it2->second) {
					ans += (min(it1->first, it2->first) * it2->second);
					it1->second -= it2->second;
					m2.erase(it2->first);
				} else {
					ans += (min(it1->first, it2->first) * it1->second);
					it2->second -= it1->second;
					if(it2->second == 0) m2.erase(it2->first);
					m1.erase(it1);
				}
			} else {
				auto it1 = m2.begin();
				auto it2 = m1.rbegin();
				if(it1->second > it2->second) {
					ans += (min(it1->first, it2->first) * it2->second);
					it1->second -= it2->second;
					m1.erase(it2->first);
				} else {
					ans += (min(it1->first, it2->first) * it1->second);
					it2->second -= it1->second;
					if(it2->second == 0) m1.erase(it2->first);
					m2.erase(it1);
				}
			}

			// auto it1 = m1.begin();
			// if(it1->second % 2) return -1;
			// else it1->second /= 2;

			// auto it2 = m2.rbegin();
			// if(it2->second % 2) return -1;
			// else it2->second /= 2;

			// if(it1->second > it2->second) {
			// 	ans += (min(it1->first, it2->first) * it2->second);
			// 	it1->second -= it2->second;
			// 	m2.erase(it2->first);
			// } else {
			// 	ans += (min(it1->first, it2->first) * it1->second);
			// 	it2->second -= it1->second;
			// 	if(it2->second == 0) m2.erase(it2->first);
			// 	m1.erase(it1);
			// }
		}

		return (m1.size() || m2.size()) ? -1 : ans;
    }
};

class Solution {
private:
vector<unordered_set<char>> row, col, box;
vector<vector<int>> emptyCells;

bool solve(vector<vector<char>>& board, int it) {
	if(it >= emptyCells.size()) return true;

	int i = emptyCells[it][0], j = emptyCells[it][1];
	int k = ((i/3)*3) + (j/3);
	for(int x = 1; x<10; x++) {
		char c = x + '0';
		if(!row[i].count(c) && !col[j].count(c) && !box[k].count(c)) {
			board[i][j] = c;
            row[i].insert(c);
			col[j].insert(c);
			box[k].insert(c);
			if(solve(board, it+1)) return true;
			row[i].erase(c)
			col[j].erase(c);
			box[k].erase(c);
		}
	}

	board[i][j] = '.';
	return false;
}

public:
    void solveSudoku(vector<vector<char>>& board) {
        row = col = box = vector<unordered_set<char>>(9);
		emptyCells = vector<vector<int>>(0);

		for(int i=0; i<9; i++) {
			for(int j=0; j<9; j++) {
				if(board[i][j] == '.') emptyCells.push_back({i,j});
				else {
					row[i].insert(board[i][j]);
					col[j].insert(board[i][j]);
					int k = ((i/3)*3) + (j/3);
					box[k].insert(board[i][j]);
				}
			}
		}

		solve(board, 0);
    }
};

class Solution {
private:
	bool cmp(vector<int> &a, vector<int> &b) {
		if(a[0] == b[0]) return a[1] > b[1];
		else return a[0] < b[0];
	}

public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);

		int ans = 0;
		for(int i=0; i<points.size(); i++) {
			for(int j=i+1; j<points.size(); j++) {
				if(points[j][1] <= points[i][1]) {
					bool isValidPair = true;
					for(int k=i+1; k<j; k++) {
						if(points[k][1] <= points[i][1] && points[k][1] >= points[j][1]) {
							isValidPair = false;
							break;
						}
					}
					if(isValidPair) ans++;
				}
			}
		}

		return ans;
    }
};

int main() {
    Solution1 s;
	vector<vector<int>> v = {{0,1,1,1},{1,1,1,1},{0,1,1,1}};
	vector<int> v1 = {8, 14, 43, 43, 80, 80, 84, 88, 88, 100};
	vector<int> v2 = {1,2,3,4,5};
	vector<vector<int>> v3 = {{6,6}};
    cout << "ANS : " << s.countSquares(v) << endl;
	// vector<int> ans = s.productQueries(919, v3);
	// for(auto i : ans) cout << i << " ";
	// s.smallestSubarrays(v1);
	// vector<int> v = {1, 1000,1,1000};
	// vector<int> ans = s.findKDistantIndices(v,1,1);
	// for(int i : ans) cout << i << " ";
	// cout << (1<<32) << endl;
	// cout << (1<<31) << endl;
	// cout << (1<<30) << endl;

	// multiset<int> ms;
	// ms.insert(1);
	// ms.insert(2);
	// ms.insert(3);

	// auto st = ms.begin();
	// auto en = ms.rbegin();
	// cout << *(st) << " ";
	// cout << *(st+2) << " ";
	// cout << *(en) << " ";
	// cout << *(en+2) << " ";
}