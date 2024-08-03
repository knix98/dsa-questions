/*
https://leetcode.com/problems/evaluate-division/

Problem also present on leetcode : I submitted solution also there

Evaluate Division

You are given an array of pairs of strings 'EQUATIONS', and an array of real numbers 'VALUES'. Each element of the 'EQUATIONS' array denotes a fraction where the first string denotes the numerator variable and the second string denotes the denominator variable, and the corresponding element in 'VALUES' denotes the value this fraction is equal to.
You are given ‘Q’ queries, and each query consists of two strings representing the numerator and the denominator of a fraction. You have to return the value of the given fraction for each query. Return -1 if the value cannot be determined.
Example :
'EQUATIONS' = { {“a”, ”s”} , {“s”, “r”} }
'VALUES' = { 1.5, 2 }
queries = { {“a”, “r” } }

For the above example (a / s) = 1.5 and (s / r) = 2 therefore (a / r) = 1.5 * 2 = 3.
Input Format :
The first line contains a single integer ‘T’ denoting the number of test cases. The test cases are as follows.

The first line of each test case contains two integers, ‘N’ and ‘Q,’ separated by a single space denoting the number of the equations and the number of queries, respectively.

The second line of each test case contains ‘N’ strings denoting the numerator variable of the 'EQUATIONS'.

The third line of each test case contains ‘N’ strings denoting the denominator variable of the 'EQUATIONS'.

The fourth line of each test case contains ‘N’ real numbers denoting the 'VALUE' of each fraction.

The fifth line of each test case contains ‘Q’ strings denoting the numerator variable for each query.

The sixth line of each test case contains ‘Q’ strings denoting the denominator variable for each query. 
Output Format :
For each test case, return the value of the fraction up to 5 decimal places or -1 if the value of the fraction cannot be determined. All values are separated by a single space.

Your output will be considered correct if the relative error does not exceed 10^(-6).
Note :
You don’t need to print anything, It has already been taken care of. Just implement the given function.
Constraints :
1 <= T <= 50
1 <= N <= 100
1 <= Q <= 100
1 <= |S| <= 10
0.0 < values[i] <= 100.0

Where '|S|' denotes the length of the variables, and 'VALUES[i]' denotes the value of the i’th equation.

Time limit: 1 sec
Sample Input 1 :
2
2 1
a s
s r
1.5 2
a
r
3 2
a abc ab
x xyz xy
0.5 1 3.4
abc pqr
xyz rew    
Sample Output 1 :
3.00000
1.00000 -1.00000
Explanation of Sample Output 1 :
In test case 1, (a / s) = 1.5 and (s / r) = 2 therefore (a / r) = 1.5 * 2 = 3.

In test case 2, for the first query, the value of (abc / xyz) is given as 1, and the value of (pqr / rew) cannot be determined.
Sample Input 2 :
2
4 2
a r w p
r w p e
1.2 2.6 1 0.5
e a
p p
2 1
a x
b y
0.5 0.4
a
y
Sample Output 2 :
2.00000 3.12000
-1.00000 
Explanation of Sample Output 2 :
In test case 1, for the first query we have p / e = 0.5 ,therefore e / p = 1 / 0.5 = 2, for the second query (a / r) * (r / w) * (w / p) = a / p which is equal to 1.2 * 2.6 * 1 = 3.12.

In test case 2, we can not determine the value of the a / y, by the given set of equations. Thus return -1.
*/



// leetcode problem solution by me ...
// DFS APPROACH
/*
basically intuition is : if by dfs we reach the target denominator (and we started dfs intially from numerator node), then we know that in the recursion call stack,
there would be those in-between nodes in the path from numerator to denominator node. So we can backtrack on this path and keep multiplying the edge weights to a 
global ans variable, which would give us the final ans.
*/
bool dfs(
    unordered_map<string, vector<pair<string, double>>> &graph, 
    string node, 
    string &destination,
    unordered_map<string, bool> &visited,
    double &ans
){
    visited[node] = true;

    if(node == destination) return true;

    for(auto p : graph[node]){
        if(!visited[p.first]){  // this would work even if visited[p.first] doesnt exist in the unordered_map, because by default its value would be 0 or false
            bool smallAns = dfs(graph, p.first, destination, visited, ans);
            if(smallAns) {
                ans *= p.second;
                return true;
            }
        }
    }

    return false;
}

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    unordered_map<string, vector<pair<string, double>>> graph;
    for(int i=0; i<values.size(); i++){
        string node1 = equations[i][0];
        string node2 = equations[i][1];

        graph[node1].push_back({node2, values[i]});
        graph[node2].push_back({node1, 1/values[i]});
    }

    vector<double> ans;
    for(auto q : queries){
        string num = q[0];
        string den = q[1];

        if(graph.count(num) > 0 && graph.count(den) > 0){
            unordered_map<string, bool> visited;
            double smallAns = 1.0;
            if(dfs(graph, num, den, visited, smallAns)) ans.push_back(smallAns);
            else ans.push_back(-1.0);
        }
        else{
            ans.push_back(-1.0);
        }
    }

    return ans;
}




// DSU APPROACH : more complex
// concepts and approach written in CN CP hand notes
// first look at that notes and then read the whole code, lot of new things are there in this solution code
#include<unordered_map>

// this func would find the root of the given node string and also attach the given node directly to its root node and then return the root node string
string getRoot(string node, unordered_map<string, string> &parent, unordered_map<string, double> &edgeWeight){
    // if the node is a new node and hence not present currently in the graph, then make a node in the graph
    if(parent.count(node) == 0){
        parent[node] = node;
        edgeWeight[node] = 1.0;
        return node;
    }

    while(parent[node] != node){
        string oldParent = parent[node];
        string newParent = parent[oldParent];

        if(oldParent == newParent) { // that means now the node is connected to the root node
            break;
        }

        parent[node] = newParent;
        edgeWeight[node] = edgeWeight[node] * edgeWeight[oldParent];
    }

    return parent[node];
}

vector<double> evaluateEquations(vector<pair<string, string>> &equations, vector<pair<string, string>> &queries, vector<double> &values) {
    unordered_map<string, string> parent; // if a/b  =>  a is parent of b  =>  parent[b] = a
    unordered_map<string, double> edgeWeight; // if a/b = 1.5  =>  edgeWeight[b] = 1.5

    for(int i=0; i<equations.size(); i++){
        string par = equations[i].first; //parent
        string chi = equations[i].second; // child

        string rp = getRoot(par, parent, edgeWeight);
        string rc = getRoot(chi, parent, edgeWeight);

        if(rp != rc){  // combine
            parent[rc] = rp;
            edgeWeight[rc] = (values[i] * edgeWeight[par]) / edgeWeight[chi];
        }
    }

    vector<double> ans;
    for(auto q : queries){
        string p = q.first;
        string c = q.second;

        if(parent.count(p) == 0 || parent.count(c) == 0){
            ans.push_back(-1.0);
            continue;
        }

        string rp = getRoot(p, parent, edgeWeight);
        string rc = getRoot(c, parent, edgeWeight);

        if(rp != rc) ans.push_back(-1.0);
        else{
            double answer = edgeWeight[c] / edgeWeight[p];
            ans.push_back(answer);
        }
    }

    return ans;
}