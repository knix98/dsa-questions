/*
String Queries

You are a string ‘S’ containing lower case English alphabets. You need to process ‘Q’ queries. For each query, you are given two integers, one denoting the type ‘Type’ of the query and the second denoting the index ‘Idx’ (0 ≤ Idx ≤ |S| - 1) for this query. The two types of queries are:
1) For each query of type-1, you need to find the largest substring that contains the same elements and the substring must include the Idx’th index, ie: you need to find the largest substring [L, R] such that L ≤ Idx ≤ R and all the elements in the substring are the same. Note that if the element at S[Idx] is equal to ‘#’ then you have to print “-1”.

2) For each query of type-2, you need to replace the character at S[Idx] with ‘#’.
For each query of type-1, find the largest substring if it exists, else print “-1”.
Example :
If ‘S’ = “aabcccaaaaa”, ‘Q’ = 5 and ‘Query’ = { {1, 0}, {1, 7}, {2, 7}, {1, 7}, {1, 9} }

For the first query, we will output 2 because the largest substring is [aa]bcccaaaaa.
For the second query, we will output 5 because the largest substring is aabccc[aaaaa].
After the third query, the string now becomes aabccca#aaa.
For the fourth query, we will output -1 because the 7’th index has the element equal to ‘#’.
For the second query, we will output 3 because the largest substring is aabccca#[aaa].
Input Format :
The first line contains a single integer ‘T’ denoting the number of test cases, then each test case follows:

The first line of each test case contains a string ‘S’, denoting the input string containing only lower case English characters.

The second line of each test case contains a single integer ‘Q’, denoting the number of queries.

The next Q lines each contain two integers ‘Type’ and ‘Idx’, denoting the type of the query and the index for the current query.
Output Format :
For each test case, print the answer for each query of type-1 in separate lines.

Output for each test case will be printed on a separate line.
Note :
You are not required to print anything; it has already been taken care of. Just implement the function.
Constraints :
1 ≤ ‘T’ ≤ 10      
1 ≤ |S| ≤ 5000   
1 ≤ ‘Q’ ≤ 100
1 ≤ ‘Type’ ≤ 2 , 0 ≤ ‘Idx’ < |S|

S only contains lower case English alphabets.
There is at least one query of type-1 for each testcase.

Time limit: 1 sec
Sample Input 1 :
2
aabcccaaaaa
5
1 0
1 7
2 7
1 7
1 9
aaaa
2
1 0
1 3
Sample Output 1 :
2
5
-1
3
4
4
Explanation For Sample Input 1 :
For test case 1 :
For the first query, we will output 2 because the largest substring is [aa]bcccaaaaa.
For the second query, we will output 5 because the largest substring is aabccc[aaaaa].
After the third query, the string now becomes aabccca#aaa.
For the fourth query, we will output -1 because the 7’th index has the element equal to ‘#’.
For the second query, we will output 3 because the largest substring is aabccca#[aaa].

For test case 2 : 
For both the queries, the largest substring will itself be equal to the original input string as all the elements are equal in the input string.
Sample Input 2 :
2
aabcd
4
1 1
2 1
1 1
1 0
aabcd
4
1 1
2 0
1 1
1 0
Sample Output 2 :
2
-1
1
2
1
-1
*/



// APPROACH 1 : DSU Solution.
/*
Basically, if we make groups of same char sequences, then when we have to put '#' somewhere then we would have to decombine the DSU (which is not possible)
So in such situations, we should think like going over the queries from back. Because if we go from back, then whenever '#' query comes, it would mean we would 
have to remove '#' from this position, and hence then we can do dsu.combine operation 
*/
class DSU{
	vector<int> parent;
	vector<int> setSize;

	public:
	DSU(int n){
		for(int i=0; i<n; i++) parent.push_back(i), setSize.push_back(1);
	}

	int root(int u){
		while(parent[u] != u){
			parent[u] = parent[parent[u]];
			u = parent[u];
		}

		return u;
	}

	void combine(int u, int v){
		int ru = root(u);
		int rv = root(v);

		if(ru != rv){
			if(setSize[ru] > setSize[rv]){
				parent[rv] = ru;
				setSize[ru] += setSize[rv];
			}
			else {
				parent[ru] = rv;
				setSize[rv] += setSize[ru];
			}
		}
	}

    int getSetSize(int u) { return setSize[u]; }
};

vector<int> stringQueries(string s, int q, vector<vector<int>> query) {
    int n = s.size();
    DSU dsu = DSU(n);

    string temp = s;  // we would put '#' in temp string only, so that when we have to remove '#' we can look up the original word here from the original string	
	
	vector<int> hashes(n, 0);  // for storing how many times a hash has been stored at a particular index. Because only after this value becomes 0 , then only we will remove '#'
    for(auto qu : query){
        if(qu[0] == 2) temp[qu[1]] = '#', hashes[qu[1]]++;
    }

    for(int i=1; i<n; i++){
        if(temp[i] != '#' && temp[i-1] == temp[i]) dsu.combine(i, i-1); 
    }

    vector<int> ans;
    for(int i=query.size()-1; i>=0; i--){
        int str_idx = query[i][1];
        if(query[i][0] == 1) {
            if(temp[str_idx] == '#') ans.push_back(-1);
            else ans.push_back(dsu.getSetSize(dsu.root(str_idx)));
        }
        else{
			hashes[str_idx]--;

			if(hashes[str_idx] == 0){ // Because only after this value becomes 0 , then only we will remove '#'
				temp[str_idx] = s[str_idx];
				if(str_idx - 1 >= 0 && temp[str_idx-1] == temp[str_idx]) dsu.combine(str_idx-1, str_idx);
				if(str_idx + 1 < n && temp[str_idx+1] == temp[str_idx]) dsu.combine(str_idx+1, str_idx);
			}
        }
    }

    reverse(ans.begin(), ans.end());

    return ans;
}   




// solved this question without DSU, solved it using lower_bound in a sorted map , so this question can be thought of as a string question instead of a DSU question
vector<int> stringQueries(string s, int q, vector<vector<int>> query) {
    map<int, int> index_range; 
    // in this map, I will store a string aaaabbbccc like [{0,4}, {4,3}, {7,3}]
    // meaning [{sequence starting at index : 0, length : 4}, ...]

    int i = 0;
    while(i < s.size())
    {
        int t = i+1;
        while(t < s.size() && s[t] == s[i]) t++;

        index_range[i] = t-i;

        i = t;
    }

    vector<int> answers;
    for(int qi = 0; qi < q; qi++){
        if(query[qi][0] == 1){
            int index = query[qi][1];

            if(s[index] == '#') {
                answers.push_back(-1);
                continue;
            }

            auto it = index_range.lower_bound(index);
            if(it != index_range.end() && it->first == index) {
                answers.push_back(it->second);
                continue;
            }

            it--;
            answers.push_back(it->second);
        }
        else{
            int index = query[qi][1];
            if(s[index] == '#') continue;

            auto it = index_range.lower_bound(index);

            if(it != index_range.end() && it->first == index) {
                // means this case : "...aaaa..." becomes "...#aaa..."  (means we have to put # at the starting index of the sequence) 
                if(index+1 < s.size() && s[index+1] == s[index]) index_range[index+1] = it->second - 1;
                index_range.erase(index);
            }
            else{
                // means this case : "...aaaa..." becomes "...aa#a..." or "...aaa#..." (means we have to put # not at the starting index of the sequence) 

                it--;  // going to the starting index of the sequence , of which the query index is a part of
                int seqLengthTillIndex = index - it->first + 1;
                if(index+1 < s.size() && s[index+1] == s[index]) index_range[index+1] = it->second - seqLengthTillIndex;
                index_range[it->first] = seqLengthTillIndex - 1;
            }

            s[index] = '#';  // lastly put the # at the query index
        }
    }

    return answers;
}