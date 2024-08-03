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



// APPROACH 1 : graph approach
void dfs(vector<vector<int>> &graph, int node, vector<bool> &visited, multiset<int> &a, multiset<int> &b, vector<int> &ninja, vector<int> &enemies){
	visited[node] = true;

    // check whether the ninja elem at this index has been found in enemies previously ?
	if(b.find(ninja[node]) == b.end()) a.insert(ninja[node]); // if no => then insert this elem in ninja multiset
	else b.erase(b.find(ninja[node])); // if yes => then remove that elem from enemies multiset

    // now check similarly for the enemies elem at this index
	if(a.find(enemies[node]) == a.end()) b.insert(enemies[node]);
	else a.erase(a.find(enemies[node]));

	for(int neighbour : graph[node]){
		if(!visited[neighbour]) dfs(graph, neighbour, visited, a, b, ninja, enemies);
	}
}

int ninjaAttack(vector<int> ninja, vector<int> enemies, vector <vector<int> >allowedSwaps)
{
	int n = ninja.size();
	
    // first make graph using allowedSwaps for connected indices
	vector<vector<int>> graph(n);
	for(auto v : allowedSwaps){
		graph[v[0]].push_back(v[1]);
		graph[v[1]].push_back(v[0]);
	}

	vector<bool> visited(n, false);

	int ans = 0;
	for(int i=0; i<n; i++){
		if(!visited[i]){
			multiset<int> a, b;  // multiset "a" qould contain elems at connected indices in ninja arr and "b" would contain similarly for enemies arr
			dfs(graph, i, visited, a, b, ninja, enemies);
			ans += a.size(); // after dfs, there would be equal elems remaining in both "a" and "b", and these elems are the ones which were
                            // found in only 1 of the arrays but not both
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
    vector<int> parent;
    vector<int> setSize;
    int n;

    public:
    DSU(int n){
        this->n = n;

        for(int i=0; i<n; i++){   // 0 based indexing from 0 to n-1
            parent.push_back(i);
            setSize.push_back(1);
        }
    }

    int findRoot(int u){
        while(parent[u] != u){
            parent[u] = parent[parent[u]];
            u = parent[u];
        }

        return u;
    }

    void combine(int u, int v){
        int ru = findRoot(u);
        int rv = findRoot(v);
        
        int combinedRoot = ru;

        if(rv != ru){
            if(setSize[rv] > setSize[ru]){
                parent[ru] = rv;
                setSize[rv] += setSize[ru];
                combinedRoot = rv;
            }
            else{
                parent[rv] = ru;
                setSize[ru] += setSize[rv];
                combinedRoot = ru;
            }
        }

        parent[ru] = combinedRoot;
        parent[rv] = combinedRoot;
    }
};

int ninjaAttack(vector<int> ninja, vector<int> enemies, vector <vector<int> >allowedSwaps)
{
    int n = ninja.size();

    DSU dsu = DSU(n);
    for(auto v : allowedSwaps){
        dsu.combine(v[0], v[1]);
    }

    // in this vector for each index i => we will store all the indices that are in a graph rooted at i
    vector<vector<int>> root_setIndices(n, vector<int>(0));
    for(int i=0; i<n; i++){
        int root_of_i = dsu.findRoot(i);
        root_setIndices[root_of_i].push_back(i);
    }

    int answer = 0;
    for(auto v : root_setIndices){
        if(v.size() > 0){
            // that means this is one connected set of indices (inside this vector)

            // the vector v contains indices that are connected, but we need to compare the nums at these indices
            // so we will store the nums at these indices in an unordered_map for comparing
            unordered_map<int,int> ninja_elems;
            for(int i=0; i<v.size(); i++){
                int ninja_index = v[i];
                ninja_elems[ninja[ninja_index]]++;
            }

            for(int i=0; i<v.size(); i++){
                int enemies_index = v[i]; 

                // checking whether the num at this index (enemies_index) is present in the ninja_elems or not
                if(ninja_elems.count(enemies[enemies_index]) == 0) answer++;
            }
        }
    }

    return answer;
}