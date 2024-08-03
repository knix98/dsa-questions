/*
https://classroom.codingninjas.com/app/classroom/me/11692/content/204224/offering/2650148/problem/14068?leftPanelTabValue=PROBLEM

After getting around 30+ referrals from a FAANG company Ninja could not able to get a single interview call. This makes Ninja very frustrated. So Ninja tried to increase his reachability by posting random stuff on a job searching platform so that a recruiter might contact him.

Fortunately, one Legendary Grandmaster(LGM) coder on CodeStudio contacted Ninja for a job offer and LGM gave Ninja a problem to solve. As Ninja is in a state of mental depression due to so many rejections. So he called you for help.

Given a string S, consisting of only the '(' or ')' parenthesis. Your task is to make the string balanced by doing the following operation zero or more times:

1. Choose a parenthesis from the string and remove it.

You need to print all possible balanced strings that can be formed from the given string by doing the above operation zero or more times.

The fate of Ninja lies in your hand.

Note:

Print only those distinct strings that can be formed by removing the minimum number of parentheses.

If the string is already balanced, return the original string.
For example:

(()

Expected string is:

[ () ]
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 5
1 <= |S| <= 15

Timit Limit: 1 sec
Sample Input 1:
1
()()()) 
Sample Output 1:
1
Explanation Of Sample Input 1:
Test case 1:
For the first test case of sample output 1, three different strings can be created by removing one extra parenthesis.
Sample Input 2:
2
()(()
()()()    
Sample Output 2:
1
1
Explanation Of Sample Input 2:
Test case 1:
For the first test case of sample output 2, we can remove the middle parenthesis to get string ()().

Test case 2:   
For the second test case of sample output 2, as the string is already balanced, hence we can return the original string.
*/






#include<bits/stdc++.h>
using namespace std;

void helper(string &s, int i, int rightBracs, int leftBracs, set<string> &ans, string t){
	int n = s.size();
	if(i == n){
		if(leftBracs == 0 && rightBracs == 0){
			ans.insert(t);
		}
		return;
	}

    // case 1 : not removing the current bracket
	helper(s, i+1, rightBracs, leftBracs, ans, t+s[i]);

    // case 2 : removing current bracket if possible
	if(s[i] == ')' && rightBracs){
		helper(s, i+1, rightBracs-1, leftBracs, ans, t);
	}
	else if(s[i] == '(' && leftBracs){
		helper(s, i+1, rightBracs, leftBracs-1, ans, t);
	}
}

vector<string> possibleBalancedString(string s) {
	int n = s.size();

    // first lets calculate how many leftBracs [(] and rightBracs [)] are extra in the string
    // this will help us in knowing exactly how many bracs we need to remove...so that we can avoid unnecessary recursion calls
	stack<char> st;
	int leftBracs=0, rightBracs=0;
	for(int i =0; i<n; i++){
		if(s[i] == '(') st.push('('), leftBracs++;
		else {
			if(st.empty() || st.top() != '(') st.push(')'), rightBracs++;
			else st.pop(), leftBracs--;
		}
	}

	set<string> ans;  // for storing only unique strings
	helper(s, 0, rightBracs, leftBracs, ans, "");
	vector<string> ansv;
	for(string i : ans) ansv.push_back(i);
	return ansv;
}

int main(){
    vector<string> ans = possibleBalancedString(")()()");
    for(string i : ans) cout << i << " ";
}


/*
https://classroom.codingninjas.com/app/classroom/me/11692/content/204224/offering/2650148/problem/14068?leftPanelTabValue=PROBLEM

After getting around 30+ referrals from a FAANG company Ninja could not able to get a single interview call. This makes Ninja very frustrated. So Ninja tried to increase his reachability by posting random stuff on a job searching platform so that a recruiter might contact him.

Fortunately, one Legendary Grandmaster(LGM) coder on CodeStudio contacted Ninja for a job offer and LGM gave Ninja a problem to solve. As Ninja is in a state of mental depression due to so many rejections. So he called you for help.

Given a string S, consisting of only the '(' or ')' parenthesis. Your task is to make the string balanced by doing the following operation zero or more times:

1. Choose a parenthesis from the string and remove it.

You need to print all possible balanced strings that can be formed from the given string by doing the above operation zero or more times.

The fate of Ninja lies in your hand.

Note:

Print only those distinct strings that can be formed by removing the minimum number of parentheses.

If the string is already balanced, return the original string.
For example:

(()

Expected string is:

[ () ]
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 5
1 <= |S| <= 15

Timit Limit: 1 sec
Sample Input 1:
1
()()()) 
Sample Output 1:
1
Explanation Of Sample Input 1:
Test case 1:
For the first test case of sample output 1, three different strings can be created by removing one extra parenthesis.
Sample Input 2:
2
()(()
()()()    
Sample Output 2:
1
1
Explanation Of Sample Input 2:
Test case 1:
For the first test case of sample output 2, we can remove the middle parenthesis to get string ()().

Test case 2:   
For the second test case of sample output 2, as the string is already balanced, hence we can return the original string.
*/






#include<bits/stdc++.h>
using namespace std;

// look at how I am checking balanced paranthesis without stack
bool isValidString(string &s){
	int n = s.size();
	int count=0;
	for(int i=0; i<n; i++){
		if(s[i] == '(') count++;
		else count--;

		if(count < 0) return false;
	}

	return (count == 0);
}

void helper(string &s, int i, int rightBracs, int leftBracs, unordered_set<string> &ans, string t){
	int n = s.size();
	if(i == n){
		if(leftBracs == 0 && rightBracs == 0){
			if(isValidString(t)) ans.insert(t);
		}
		return;
	}

	// case 1 : not removing the current bracket
	helper(s, i+1, rightBracs, leftBracs, ans, t+s[i]);

	// case 2 : removing current bracket if possible
	if(s[i] == ')' && rightBracs){
		helper(s, i+1, rightBracs-1, leftBracs, ans, t);
	}
	else{
		helper(s, i+1, rightBracs, leftBracs-1, ans, t);
	}
}

vector<string> possibleBalancedString(string s) {
	int n = s.size();

	// first lets calculate how many leftBracs [(] and rightBracs [)] are extra in the string
    // this will help us in knowing exactly how many bracs we need to remove...so that we can avoid unnecessary recursion calls
	// this is also necessary because we have to remove the minimum number of extra parenthesis
	int leftBracs=0, rightBracs=0;
	for(int i =0; i<n; i++){
		if(s[i] == '(') leftBracs++;
		else {
			if(leftBracs > 0) leftBracs--;
			else rightBracs++;
		}
	}

	unordered_set<string> ans;  // so that we store only unique strings
	helper(s, 0, rightBracs, leftBracs, ans, "");
	vector<string> ansv;
	for(string i : ans) ansv.push_back(i);
	return ansv;
}

// int main(){
//     vector<string> ans = possibleBalancedString(")()()");
//     for(string i : ans) cout << i << endl;
// }