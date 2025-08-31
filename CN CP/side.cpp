// #include <bits/stdc++.h>
// using namespace std;

// // #define ll long long

// // ll djikstra(vector<vector<pair<int, ll>>> &graph, int &src, int &dest)
// // {
// //     ll minDist[n] = {LONG_LONG_MAX};
// //     priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
// //     minDist[src] = 1;
// //     pq.push({1, src});

// //     while (!pq.empty())
// //     {
// //         ll dist = pq.top().first;
// //         int node = pq.top().second;
// //         pq.pop();

// //         if (minDist[node] < dist)
// //             continue;

// //         for (auto edge : graph[node])
// //         {
// //             int neigh = edge.first;
// //             ll weight = edge.second;
// //             if (dist * weight < minDist[neigh])
// //             {
// //                 minDist[neigh] = dist * weight;
// //                 pq.push({minDist[neigh], neigh});
// //             }
// //         }
// //     }

// //     return minDist[dest] < LONG_LONG_MAX ? minDist[dest] : -1;
// // }

// // long long int minEffortsRequired(vector<pair<pair<int, int>, long long int>> &edges, int n, int src, int dest)
// // {
// //     vector<vector<pair<int, ll>>> graph(n);
// //     for (auto edge : edges)
// //     {
// //         graph[edge.first.first].push_back({edge.first.second, edge.second});
// //     }

// //     return djikstra(graph, src, dest);
// // }

// class Solution
// {
// public:
//     int calculate(string s)
//     {
//         int l = 0;
//         int leftNum = 0;
//         int ans = 0;
//         int i = 0;

//         while (i < s.size())
//         {
//             cout << "i : " << i << ", l : " << l << ", leftNum : " << leftNum << ", ans : " << ans << endl;
//             if (s[i] == ' ')
//                 i++;
//             else if (s[i] == '*' || s[i] == '/')
//             {
//                 if (l < i)
//                     leftNum = INT(s, l, i - 1);

//                 int r = i + 1;
//                 while (r < s.size() && (s[r] - '0' >= 0 || s[r] == ' '))
//                     r++;
//                 int rightNum = INT(s, i + 1, r - 1);

//                 if (s[i] == '*')
//                     leftNum = leftNum * rightNum;
//                 else
//                     leftNum = leftNum / rightNum;

//                 l = i = r;
//             }
//             else if (s[i] == '+' || s[i] == '-')
//             {
//                 if (l < i)
//                     leftNum = INT(s, l, i - 1);

//                 ans += leftNum;

//                 leftNum = 0;
//                 l = i++;
//             }
//             else
//                 i++;
//         }

//         if (l < i)
//             leftNum = INT(s, l, i - 1);
//         ans += leftNum;
//         return ans;
//     }

// private:
//     // int sum(string &s) {
//     //     int ans = 0;
//     //     int i = 0;
//     //     while(i < s.size()) {
//     //         int n = s[i] == '-' ? -1 : 1;
//     //         if(s[i] == '-' || s[i] == '+') {
//     //             i++;
//     //         }
//     //         int r = i+1;
//     //         while(r < s.size() && s[r] - '0' >= 0) r++;

//     //         n *= INT(s.substr(i, r-i));
//     //         ans += n;
//     //         i = r;
//     //     }

//     //     return ans;
//     // }

//     // void parse(string &s, char sign) {
//     //     int i = 0;
//     //     while(i < s.size()) {
//     //         if(s[i] == sign) {
//     //             int l = i-1;
//     //             int r = i+1;
//     //             while(l >= 0 && (s[l] - '0' >= 0)) l--;
//     //             l++;
//     //             while(r < s.size() && (s[r] - '0' >= 0)) r++;
//     //             r--;

//     //             string num = eval(s, l, i, r);

//     //             s = s.substr(0, l) + num + s.substr(r+1);

//     //             i = l + num.size();
//     //         }
//     //         else i++;
//     //     }
//     // }

//     // string eval(string &s, int l, int i, int r) {
//     //     int left = INT(s.substr(l, i-l));
//     //     int right = INT(s.substr(i+1, r-i));
//     //     char sign = s[i];

//     //     int num;
//     //     if(sign == '/') num = left / right;
//     //     else if(sign == '*') num = left * right;
//     //     else if(sign == '+') num = left + right;
//     //     else if(sign == '-') num = left - right;

//     //     return STR(num);
//     // }

//     int INT(string &s, int l, int r)
//     {
//         cout << s.substr(l, r - l + 1) << endl;
//         int ans = 0;
//         long long mul = 1;
//         while (r >= l && s[r] != '-' && s[r] != '+')
//         {
//             if (s[r] != ' ')
//             {
//                 ans += ((s[r] - '0') * mul);
//                 mul *= 10;
//             }
//             r--;
//         }
//         if (r >= l && s[r] == '-')
//             ans *= -1;
//         cout << "INT : " << ans << endl;
//         return ans;
//     }

//     // string STR(int n) {
//     //     string s = "";
//     //     while(n) {
//     //         int dig = n%10;
//     //         n /= 10;
//     //         s = (char)(dig + (int)('0')) + s;
//     //     }
//     //     return s;
//     // }

//     // string removeSpaces(string s) {
//     //     string ans = "";
//     //     for(char c : s) if(c != ' ') ans += c;
//     //     return ans;
//     // }
// };

// class Solution1
// {
// public:
//     int calculate(string s)
//     {
//         removeSpaces(s);
//         return calculate(s, 0).first;
//     }

// private:
//     pair<int, int> calculate(string &s, int l)
//     {
//         int ans = 0;
//         int lit = l, it = l;

//         while (it < s.size() && s[it] != ')')
//         {
//             if (s[it] == '+' || s[it] == '-')
//             {
//                 if (lit < it)
//                     ans += INT(s, lit, it - 1);
//                 lit = it++;
//             }
//             else if (s[it] == '(')
//             {
//                 pair<int, int> smallAns = calculate(s, it + 1);
//                 if (lit < it && s[lit] == '-')
//                     smallAns.first *= -1;
//                 // cout << s.substr(it, 2) << ", " << smallAns.first << ", " << smallAns.second << endl;
//                 ans += smallAns.first;
//                 lit = it = smallAns.second + 1;
//             }
//             else
//                 it++;
//         }

//         if (lit < it)
//             ans += INT(s, lit, it - 1);
//         return {ans, it};
//     }

//     int INT(string &s, int l, int r)
//     {
//         int ans = 0;
//         long long mul = 1;
//         while (r >= l && s[r] != '-' && s[r] != '+')
//         {
//             ans += ((s[r] - '0') * mul);
//             mul *= 10;
//             r--;
//         }
//         if (r >= l && s[r] == '-')
//             ans *= -1;
//         return ans;
//     }

//     void removeSpaces(string &s)
//     {
//         int i = 0, j = 0;
//         while (j < s.size())
//         {
//             if (s[j] != ' ')
//             {
//                 s[i++] = s[j];
//             }

//             j++;
//         }

//         s = s.substr(0, i);
//     }
// };

// class Solution2
// {
// public:
//     int calculate(string s)
//     {
//         int currSign = 1;
//         int currNum = 0;
//         stack<pair<int, int>> st;
//         st.push({1, 0});

//         for (char c : s)
//         {
//             if (c == ' ')
//                 continue;

//             if (isdigit(c))
//             {
//                 currNum = currNum * 10 + (c - '0');
//             }
//             else if (c == '+' || c == '-' || c == ')')
//             {
//                 pair<int, int> top = st.top();
//                 st.pop();
//                 top.second += (currSign * currNum);

//                 if (c == '+' || c == '-')
//                 {
//                     st.push(top);
//                     currNum = 0;
//                     currSign = c == '+' ? 1 : -1;
//                 }
//                 else
//                 { // means c == ')'
//                     pair<int, int> secondTop = st.top();
//                     st.pop();
//                     secondTop.second += (top.first * top.second);
//                     st.push(secondTop);
//                     currNum = 0;
//                     currSign = 1;
//                 }
//             }
//             else if (c == '(')
//             {
//                 st.push({currSign, 0});
//                 currSign = 1;
//                 currNum = 0;
//             }
//         }

//         pair<int, int> ans = st.top();
//         ans.second += (currSign * currNum);
//         return ans.second; // no need to do ans.first*ans.second, since for global ans pair sign would always be + or 1
//     }
// };

// class Solution3
// {
// public:
//     int calculate(string &s)
//     {
//         return calculate(s, 0).first;
//     }

// private:
//     pair<int, int> calculate(string &s, int i) {
//         char lastSign = '+';
//         int lastNum = 0;
//         int currNum = 0;
//         int ans = 0;

//         while(i < s.size() + 1) {
//             // cout << s[i] << " : " << ans << " " << lastNum << " " << lastSign << " " << currNum << endl;
//             if(i < s.size() && s[i] == ' ') {
//                 i++;
//                 continue;
//             }
            
//             if(i == s.size() || s[i] == '+' || s[i] == '-' || s[i] == ')') {
//                 if(lastSign == '*') {
//                     ans += (lastNum * currNum);
//                 }
//                 else if(lastSign == '/') {
//                     ans += (lastNum / currNum);
//                 }
//                 else { // means lastSign == + or -
//                     if(lastSign == '-') currNum = -currNum;
//                     ans += currNum;
//                 }
                
//                 currNum = lastNum = 0;
//                 if(s[i] == ')' || i == s.size()) break;
//                 else lastSign = s[i++];
//             }
//             else if(isdigit(s[i])) {
//                 currNum = currNum*10 + (s[i++] - '0');
//             }
//             else if(s[i] == '(') {
//                 pair<int, int> smallAns;
//                 smallAns = calculate(s, i+1);
//                 currNum = smallAns.first;
//                 cout << s.substr(i, 2) << " : " << smallAns.first << "," << ans << endl;
//                 i = smallAns.second;
//             }
//             else if(s[i] == '*' || s[i] == '/') {
//                 if(lastSign == '*') {
//                     lastNum = lastNum * currNum;
//                 }
//                 else if(lastSign == '/') {
//                     lastNum = lastNum / currNum;
//                 }
//                 else {
//                     if(lastSign == '-') currNum = -currNum;
//                     lastNum = currNum;
//                 }
//                 currNum = 0;
//                 lastSign = s[i++];
//             }
//         }

//         return {ans, i+1};
//     }
// };

// // "(1+(4+5+2)-3)+(6+8)"
// int main()
// {
//     Solution3 s;
//     // cout << s.calculate("1*2-3/4+5*6-7*8+9/10");
//     // cout << s.calculate("(1+(4+5+2)-3)+(6+8)");
//     string str = "2*(5+5*2)/3+(6/2+8)";
//     // str = "(5+5*2)";
//     cout << s.calculate(str);
// }

// // class Solution
// // {
// // public:
// //     int calculate(string s)
// //     {
// //         int len = s.length();
// //         if (len == 0)
// //             return 0;
// //         stack<int> stack;
// //         int currentNumber = 0;
// //         char operation = '+';
// //         for (int i = 0; i < len; i++)
// //         {
// //             char currentChar = s[i];
// //             if (isdigit(currentChar))
// //             {
// //                 currentNumber = (currentNumber * 10) + (currentChar - '0');
// //             }
// //             if (!isdigit(currentChar) && !iswspace(currentChar) || i == len - 1)
// //             {
// //                 if (operation == '-')
// //                 {
// //                     stack.push(-currentNumber);
// //                 }
// //                 else if (operation == '+')
// //                 {
// //                     stack.push(currentNumber);
// //                 }
// //                 else if (operation == '*')
// //                 {
// //                     int stackTop = stack.top();
// //                     stack.pop();
// //                     stack.push(stackTop * currentNumber);
// //                 }
// //                 else if (operation == '/')
// //                 {
// //                     int stackTop = stack.top();
// //                     stack.pop();
// //                     stack.push(stackTop / currentNumber);
// //                 }
// //                 operation = currentChar;
// //                 currentNumber = 0;
// //             }
// //         }
// //         int result = 0;
// //         while (stack.size() != 0)
// //         {
// //             result += stack.top();
// //             stack.pop();
// //         }
// //         return result;
// //     }
// // };

// // class Solution
// // {
// // public:
// //     int calculate(string s)
// //     {
// //         int length = s.length();
// //         if (length == 0)
// //             return 0;
// //         int currentNumber = 0, lastNumber = 0, result = 0;
// //         char sign = '+';
// //         for (int i = 0; i < length; i++)
// //         {
// //             char currentChar = s[i];
// //             if (isdigit(currentChar))
// //             {
// //                 currentNumber = (currentNumber * 10) + (currentChar - '0');
// //             }
// //             else if (!iswspace(currentChar) || i == length - 1)
// //             {
// //                 if (sign == '+' || sign == '-')
// //                 {
// //                     result += lastNumber;
// //                     lastNumber = (sign == '+') ? currentNumber : -currentNumber;
// //                 }
// //                 else if (sign == '*')
// //                 {
// //                     lastNumber = lastNumber * currentNumber;
// //                 }
// //                 else if (sign == '/')
// //                 {
// //                     lastNumber = lastNumber / currentNumber;
// //                 }
// //                 sign = currentChar;
// //                 currentNumber = 0;
// //             }
// //         }
// //         result += lastNumber;
// //         return result;
// //     }
// // };


#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll const mod = 1e9;

struct Edge{
	int u;
	int v;
	int w;
};

class cmp{
	public:
	bool operator() (Edge &a, Edge &b) {
		return a.w < b.w;
	}
};

class DSU{
	public:
	vector<int> parent;
	vector<int> size;
	ll connectedNodesPairs;

	DSU(int n) {
		for(int i=0; i<=n; i++) parent.push_back(i), size.push_back(1);
		connectedNodesPairs = 0;
	}

	int root(int u) {
		while(parent[u] != u) {
			parent[u] = parent[parent[u]];
			u = parent[u];
		}

		return u;
	}

	void combine(int u, int v) {
		int ru = root(u);
		int rv = root(v);

		if(ru == rv) return;

		ll sru = size[ru], srv = size[rv];
		connectedNodesPairs = (connectedNodesPairs - (((sru * (sru-1)) / 2) % mod)) % mod;
		connectedNodesPairs = (connectedNodesPairs - (((srv * (srv-1)) / 2) % mod)) % mod;

		if(sru > srv) {
			parent[rv] = ru;
			sru = size[ru] = size[ru] + size[rv];
		}
		else {
			parent[ru] = rv;
			sru = size[rv] = size[rv] + size[ru];
		}

		connectedNodesPairs = (connectedNodesPairs + (((sru * (sru-1)) / 2) % mod)) % mod;
	}
};

int main() {
	int v, e;
	priority_queue<Edge, vector<Edge>, cmp> maxpq;
	cin >> v >> e;
 
	for(int i=0; i<e; i++) {
		Edge e;
		cin >> e.u >> e.v >> e.w;
		maxpq.push(e);
	}
 
	DSU dsu = DSU(v);
 
	int ans = 0;
	while(!maxpq.empty()) {
		Edge e = maxpq.top();
		maxpq.pop();
 
		dsu.combine(e.u, e.v);
		ans = (ans + ((dsu.connectedNodesPairs * e.w) % mod)) % mod;
	}
 
	cout << ans;
 
	return 0;
}  

// int main() {
// 	int v, e;
// 	// Hard-coded input values
// 	v = 6;
// 	e = 7;
	
// 	priority_queue<Edge, vector<Edge>, cmp> maxpq;
	
// 	// Hard-coded edge values
// 	Edge edges[] = {
// 		{1, 2, 10},
// 		{2, 3, 2},
// 		{4, 3, 5},
// 		{6, 3, 15},
// 		{3, 5, 4},
// 		{4, 5, 3},
// 		{2, 6, 6}
// 	};
	
// 	for(int i = 0; i < e; i++) {
// 		maxpq.push(edges[i]);
// 	}

// 	DSU dsu = DSU(v);

// 	int ans = 0;
// 	while(!maxpq.empty()) {
// 		Edge e = maxpq.top();
// 		maxpq.pop();
// 		cout << e.u << " " << e.v << " " << e.w << " " << endl;

// 		dsu.combine(e.u, e.v);
// 		ans = (ans + ((dsu.connectedNodesPairs * e.w) % mod)) % mod;
// 		cout << dsu.connectedNodesPairs << " " << ans << endl;
// 	}

// 	cout << ans;

// 	return 0;
// }