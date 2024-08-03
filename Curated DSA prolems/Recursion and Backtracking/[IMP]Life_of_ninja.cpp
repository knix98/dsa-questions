/*
https://classroom.codingninjas.com/app/classroom/me/11692/content/204224/offering/2650148/problem/14067?leftPanelTabValue=PROBLEM

Ninja always dreams to work in a FAANG company but unfortunately, Ninja landed up in a startup as a Technical Content Engineer.

After getting rejection from FAANG companies, Ninja tried to approach some unicorn and fintech startups. In the Online assessment, Ninja got stuck in a problem so Ninja called you to solve the problem.

You are given a string ‘STR’ consisting of English lowercase letters.

Your task is to find out all the "Abbr" strings of ‘STR’ and return an array/list of these "Abbr" strings sorted in increasing order.

The fate of Ninja lies in your hand.

Note:

A string is said to be an "Abbr" string of ‘STR’ if we remove a substring of length ‘X’ from ‘STR’ and put the number ‘X’ at the place of the removed substring. 
We can not remove two consecutive substrings or we can say "Abbr" strings will never have two consecutive numbers.
For example:

If ‘STR’ = “abc”,
Sorted "Abbr" strings of ‘STR’ are: [“1b1”, “1bc”, “2c”, “3”, “a1c”, “a2”, “ab1”, “abc”].
Detailed explanation ( Input/output format, Notes, Images )
Sample input 1:
3
do
or
die
Sample output 1:
1o 2 d1 do 
1r 2 o1 or 
1i1 1ie 2e 3 d1e d2 di1 die 
Sample input 2:
2
n
code
Sample output 2:
1 n
1o1e  1o2  1od1  1ode  2d1  2de  3e  4  c1d1  c1de  c2e  c3  co1e  co2  cod1  code 
*/



void helper(vector<string> &ans, string &s, int i, string t, bool numPossible){
	int n = s.size();
	if(i == n) {
		ans.push_back(t);
		return;
	}

	if(numPossible){
		int num = 1;
		for(int j=i; j<n; j++){
			helper(ans, s, i+num, t+(char)(num+48), false);
			num++;
		}
	}

	helper(ans, s, i+1, t+s[i], true);
}

vector < string > findAbbr(string & str) {
	vector<string> ans;
	helper(ans, str, 0, "", true);
	return ans;
}