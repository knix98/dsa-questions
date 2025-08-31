/*
NINJA ATTACK

Ninja has built his team of ninjas to fight with the enemies in his city. Ninja made a plan of attacking all his enemies. In his team, every ninja has his own range of hitting and they had secretly got the hitting range of their enemies as well. So Ninja allowed some swaps between his ninjas so that they can minimize the hamming distance that is the number of positions where the hitting range of enemies and ninjas are different.
Your task is to write a code that can minimize the hamming distance. You are being provided with two arrays ‘ninja’ and ‘enemies’ both of the same size and an array ‘allowedSwaps’ where each allowedSwaps[i] = [ ai, bi ] indicates that you are allowed to swap the elements at index ai and index bi.
The Hamming distance of two arrays of the same length, ninja, and enemies, is the number of positions where the elements are different.

Example :
Consider the case ‘ninja’array is [ 1, 2, 3, 4 ], ‘enemies’array is [ 2, 1, 4, 5 ] and ‘allowedSwaps’ are  = [ [ 0, 1 ], [ 2, 3 ] ] so after swapping in best manner according to ‘allowedSwaps’ our ‘ninja’ array becomes [ 2, 1, 4, 3 ]. So minimum Hamming distance is ‘1’ as now there is only one different element as compared to ‘ninja’ and ‘enemies’ array index.

Note :
1. You are allowed to do as many swap operations on the ‘ninja’ array as you want but according to the ‘allowedSwap’ array.
2. You are not required to print anything explicitly. It has already been taken care of. Just implement the function.

Input Format :
The first line of input contains a ‘T’ number of test cases.

The first line of each test case contains an integer ‘n’, which represents the size of the array ‘ninja’ and ‘enemies’.

The second line of each test case contains the ‘n’ space-separated integer of array ‘ninja’.

The third line of each test case contains the ‘n’ space-separated integer of array ‘enemies’.

The fourth line of each test case contains an integer ‘m’ denoting the number of rows in array ‘allowedSwap’. Then, ‘m’ lines follow.

Each line contains two space-separated integers denoting the array values.

Output Format :
For each test case, return the minimum hamming distance of the ‘ninja’ and ‘enemies’ array.

Constraints :
1 <= T <= 100
1 <= N <=  10^3
0 <= ninja[i], enemies[i] < 10^5
0 <= allowedSwaps[i] <=10^5      

Where ‘T’ represents the number of test cases, ‘N’ represents the size of the ‘ninja’ and ‘enemies’ array and ninja[i], enemies[i], and allowedSwaps[i] represents the element in the array.

Time Limit: 1 second    

Sample Input 1 :
2
4
1 2 3 4
2 1 4 5
2
0 1
2 3
4
1 2 3 4
1 3 2 4
1
2 3
Sample Output 1 :
1
2
Explanation of Sample Input 1 :
Test Case 1:

Before the swapping hamming distance is ‘2’ because in these arrays ‘2’ index has different elements.
So according to this test case, ‘ninja’ = [ 1, 2, 3, 4 ], ‘enemies’ = [ 2, 1, 4, 5 ] and ‘allowedSwaps’ = [ [ 0, 1 ], [ 2, 3 ] ] so after swapping in best manner according to ‘allowedSwaps’ our ‘ninja’ array becomes [ 2, 1, 4, 3 ] so minimum Hamming distance is ‘1’ as now there is only one different element as compared to ‘ninja’ and ‘enemies’ array index.

Test Case 2:

So according to this test case, ‘ninja’ = [ 1, 2, 3, 4 ], ‘enemies’ = [ 1, 3, 2, 4 ], and even after swapping the minimum Hamming distance is ‘2’ as there are ‘2’  different element as compared to ‘ninja’ and ‘enemies’ array index.
Sample Input 2 :
2
5
5 1 2 4 3
1 5 4 2 3
4
0 4
4 2
1 3
1 4  
3
1 2 3
3 1 2
0
Sample Output 2 :
0
3
*/



/*
APPROACH 1 : graph approach : first make graph of connected indices from edges given
then traverse over a connected component and first collect all elems at these indices from enemies and then collect all elems at these indices from ninja
and compare

Time : O(n) , where n = number of elems in ninja. One could say that O(v+e), but since there are no cycles in graph so e ~ v-1
Space : O(n)
*/
void traverse(vector<vector<int>> &graph, vector<int> &visited, int visitMark, vector<int> &v, int node, unordered_map<int, int> &elems) {
    if(visitMark == 1) elems[v[node]]++;
    else if(elems[v[node]]) elems[v[node]]--;  // decreasing count when traversing over ninja (visitMark = 2)

    visited[node] = visitMark;

    for(int neighbour : graph[node]) {
        if(visited[neighbour] != visitMark) {
            traverse(graph, visited, visitMark, v, neighbour, elems);
        }
    }
}

int ninjaAttack(vector<int> ninja, vector<int> enemies, vector <vector<int> >allowedSwaps)
{
    int n = ninja.size();
    vector<vector<int>> graph(n, vector<int>(0));
    for(auto edge : allowedSwaps) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    vector<int> visited(n, 0);
    int ans = 0;  // number of elems in enemies that have no matching elem in ninja even after internal swapping in ninja

    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            unordered_map<int, int> elems;  // in this we will store the elems found first in enemies and then found in ninja

            traverse(graph, visited, 1, enemies, i, elems);  // visitMark = 1 for enemies traversal
            traverse(graph, visited, 2, ninja, i, elems);  // visitMark = 2 for ninja traversal

            for(auto it : elems) {
                ans += it.second;  // the enemies elems which were not found in ninja can be added to the ans
            }
        }
    }

    return ans;
}




// APPROACH 2 :
// suppose legitimate swaps == [{1,2}, {2,6}, {6,4}] 
// therefore we can say : 1,2,6,4 indices are connected (means numbers on these indices can be arranged in any order by swapping)
// therefore we will then check that how many numbers on indices 1,2,4,6 in the enemies and ninja arrays are same
// suppose in ninja, nums on indices 1,2,4,6 == [2,3,4,5] and in enemies [2,3,4,6], then since 1 num is different so , 1 gets added to hamming distance
// and the indices which are not in the allowed_swap array, will form a graph with a single node only that is themselves
class DSU {
public:
    unordered_map<int, int> parent;
    unordered_map<int, int> setSize;

	DSU(vector<int> &v) {
		for(int i : v) {
			parent[i] = i;
			setSize[i] = 1;
		}
	}

	int root(int u) {
		if(parent.count(u) == 0) return -1;

		while(parent[u] != u) {
			parent[u] = parent[parent[u]];
			u = parent[u];
		}

		return u;
	}

	void combine(int u, int v) {
		int ru, rv;
		if(parent.count(u) == 0) {
			parent[u] = ru = u;
			setSize[u] = 1;
		}
		else {
			ru = root(u);
		}
		if(parent.count(v) == 0) {
			parent[v] = rv = v;
			setSize[v] = 1;
		}
		else {
			rv = root(v);
		}

		if(setSize[ru] > setSize[rv]) {
			parent[rv] = ru;
			setSize[ru] += setSize[rv];
		} else {
			parent[ru] = rv;
			setSize[rv] += setSize[ru];
		}
	}
};

int ninjaAttack(vector<int> ninja, vector<int> enemies, vector <vector<int> >allowedSwaps)
{
	DSU dsu(ninja);
	for(auto v : allowedSwaps) {
		dsu.combine(ninja[v[0]], ninja[v[1]]);
	}

	int ans = 0;
	for(int i=0; i<ninja.size(); i++) {
		if(dsu.root(ninja[i]) != dsu.root(enemies[i])) ans++;
	}

	return ans;
}