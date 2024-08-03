/*
https://classroom.codingninjas.com/app/classroom/me/11692/content/204218/offering/2650138/problem/14342?leftPanelTabValue=PROBLEM

You are given a string ‘S’ consisting of distinct letters. Your task is to find the rank of the given string.

The rank of a string is defined as the position of the string when all possible permutations of the given string are arranged in lexicographical order.

For Example :
Consider ‘S’ = "cdb",
All possible permutations of the string S in lexicographical order will be: [“bcd”, “bdc”, “cbd”, “cdb”, “dbc”, “dcb”]. The rank of ‘cdb’ is 4. Hence, the answer is 4.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
2
bcd
cdb
Sample Output 1:
1
4
Explanation for Sample Test Case 1:
All possible permutations of the string “bcd” in the lexicographical order will be [“bcd”, “bdc”, “cbd”, “cdb”, “dbc”, “dcb”].

Test Case 1:
The rank of “bcd” is 1. Hence, the answer is 1.

Test Case 2:
The rank of “cdb” is 4. Hence, the answer is 4.
Sample Input 2:
2
coding
string
Sample Output 2:
100
598
*/


// APPROACH : https://takeuforward.org/data-structure/lexicographic-rank-of-a-string/
#define ll unsigned long long

void populate_count_arr(int *count, string &s){
	for(char c : s){
		count[c - 'a']++;
	}
}

int rank_of_char(int *count, int idx){
	int rank = 0;
	int i=0;
	while(i < idx) rank += count[i++];

	// also decreasing 1 from idx , because the curr char is considered and should be removed from count arr
	count[idx]--;

	return rank;
}

ll lexicRank(string s)
{	
	int n = s.size();
	int count[26] = {0};
	populate_count_arr(count, s);

	ll factorial = 1;
	for(int i=2; i<n; i++) factorial *= i;

	ll ans = 0;
	int max_num_in_factorial = n-1;
	for(int i=0; i<n; i++){
		int rank_of_curr_char = rank_of_char(count, s[i] - 'a');
		ans += (rank_of_curr_char * factorial);
		if(max_num_in_factorial > 0) factorial /= max_num_in_factorial--;
	}

	return ans+1;
}