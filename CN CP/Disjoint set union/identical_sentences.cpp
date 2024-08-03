/*
Identical sentences

You are given two sentences, ‘word1’ and ‘word2’, represented as an array of strings of size ‘n’ and ‘m’, respectively. You are also given an array called ‘pairs’. Each element in ‘pairs’ is of the form ‘[u, v]’ where ‘u’ and ‘v’ are strings.
Properties of the array ‘pairs’:
If ‘[u, v]’ or ‘[v, u]’ is present in ‘pairs’, then the words (or strings) ‘u’ and ‘v’ are identical.
If ‘u’ and ‘x’ are identical, and ‘v’ and ‘x’ are identical, then the words ‘u’ and ‘v’ are identical.
Every word is identical to itself, i.e., the word ‘u’ and ‘u’ are always identical.
For two sentences, ‘word1’ and ‘word2’ to be identical:
For every word (‘word1[i]’) in ‘word1’, the words ‘word1[i]’ and ‘word2[i]’ must be identical.
‘word1’ and ‘word2’ must have the same number of words.
Using the array ‘pairs’, you have to determine if ‘word1’ and ‘word2’ are identical.
Example :
‘word1’ = [“exceptional”, “coding”, “skills”]
‘word2’ = [“great”, “coding”, “talent”]
‘pairs’ = [ [“exceptional”, “good”], [“great”, “good”], [“skills”, “talent”] ]

For each word in ‘word1’, we have:
1. “exceptional” = “great”, because “exceptional” = “good” and “good” = “great”
2. “coding” = “coding”, as every word is identical to itself.
3. “skills” = “talent”, because [“skills”, “talent”] is present in ‘pairs’.

As every word in ‘word1’ is identical to the corresponding word in ‘word2’, the given sentences are identical.
Note :
1. The array ‘pairs’ can have words that are not present in ‘word1’ and ‘word2’.
2. Each pair ‘[u, v]’ in ‘pairs’ is unique, and if a pair ‘[u, v]’ is present, then there will never be a pair ‘[v, u]’.
3. You do not need to print anything; it has already been taken care of. Just implement the function.
Input format :
The first line of input contains an integer ‘T’ which denotes the number of test cases. Then, the ‘T’ test cases follow.

The first line of each test case contains three integers, ‘n’, ‘m’, and ‘p’ denoting the number of elements in array ‘word1’, ‘word2’, and ‘pairs’.

The second line of each test case contains ‘n’ space-separated words denoting ‘word1’.

The third line of each test case contains ‘m’ space-separated words denoting ‘word2’.

The following ‘p’ lines of each test case contain two space-separated words denoting an element in ‘pairs’.

For more clarity, please refer to the sample inputs. 
Output format:
For every test case, return true if the sentences ‘word1’ and ‘word2’ are identical, else return false.
Constraints:
1 <= T <= 1
1 <= n, m <= 1000
0 <= p <= 2000
Each element of ‘pairs’ contains exactly two words.
Length of each word in ‘word1’, ‘word2’ and ‘pairs[i]’ is in the range [1, 20].
Value of each word in ‘word1’, ‘word2’ and ‘pairs[i]’ varies from [a, z].

Where ‘T’ is the number of test cases, ‘n’ is the number of words in ‘word1’, ‘m’ is the number of words in ‘word2’, and ‘p’ is the number of elements in ‘pairs’.

Time limit: 1 second
Sample input 1 :
2
2 2 4
better life
fine country  
better good
fine great
great good
life fine
3 3 1
this is it
that is it
that this
Sample output 1 :
False
True
Explanation of sample input 1 :
Test Case 1:
‘word1’ = [“better”, “life”]
‘word2’ = [“fine”, “country”]
‘pairs’ = [ [“better”, “good”], [“fine”, “great”], [“great”, “good”], [“life”, “fine” ] ]

For each word in ‘word1’, we have:
1. “better” = “fine”, because “better” = “good”, “good” = “great” and “great” = “fine”.
2. “life” is not identical to “country”.

As the last word in ‘word1’ is not identical to the last word in ‘word2’, the given sentences are not identical.

Test Case 2:
‘word1’ = [“this”, “is”, “it]
‘word2’ = [“that”, “is”, “it”]
‘pairs’ = [ [“that”, “this”] ]

For each word in ‘word1’, we have:
1. “this” = “that”, because [“that”, “this”] is present in ‘pairs’.
2. “is” = “is”, as every word is identical to itself.
3. “it” = “it”, as every word is identical to itself.

As every word in ‘word1’ is identical to the corresponding word in ‘word2’, the given sentences are identical.
Sample input 2 :
2
3 3 0
sample input one
sample input one
4 4 3
this too shall pass
that one must pass
this that
one two
two too
Sample output 2 :
True
False
*/



// here we would have to make a DSU of strings (parent and child would be strings instead of int)
// look at the code quickly
#include<unordered_map>

class DSU{
    unordered_map<string, string> parent;
    unordered_map<string, int> setSize;
    
    public :
    DSU(vector<string> &word1, vector<string> &word2){
        for(int i=0; i<word1.size(); i++){
            parent[word1[i]] = word1[i];
            setSize[word1[i]] = 1;

            if(word1[i] != word2[i]){
                parent[word2[i]] = word2[i];
                setSize[word2[i]] = 1;
            }
        }
    }

    string findRoot(string s){
        while(parent[s] != s){
            parent[s] = parent[parent[s]];
            s = parent[s];
        }

        return s;
    }

    void combine(string u, string v){
        // if((parent.count(u) == 0) || (parent.count(v) == 0)) return;
        if(parent.count(u) == 0) {  // if a new word is given as connected to one of the original words, then insert this new word also in the DSU and then combine operation
            parent[u] = u;
            setSize[u] = 1;
        }
        if(parent.count(v) == 0) {
            parent[v] = v;
            setSize[v] = 1;
        }

        string ru = findRoot(u);
        string rv = findRoot(v);

        string combinedRoot = ru;
        if(ru != rv){
            if(setSize[ru] > setSize[rv]){
                parent[rv] = ru;
                setSize[ru] += setSize[rv];
                combinedRoot = ru;
            }
            else{
                parent[ru] = rv;
                setSize[rv] += setSize[ru];
                combinedRoot = rv;
            }
        }

        parent[u] = combinedRoot;
        parent[v] = combinedRoot;
    }
};

bool identicalSentences(vector<string> word1, vector<string> word2, vector<vector<string>> pairs, int n, int m, int p) {
    if(n != m) return false;

    DSU dsu = DSU(word1, word2);

    for(int i=0; i<p; i++){
        dsu.combine(pairs[i][0], pairs[i][1]);
    }

    for(int i=0; i<n; i++){
        if(word1[i] == word2[i]) continue;

        string ru = dsu.findRoot(word1[i]);
        if(ru != dsu.findRoot(word2[i])) return false;
    }

    return true;
}





