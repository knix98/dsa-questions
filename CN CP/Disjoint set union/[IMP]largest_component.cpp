/*
Problem statement can also be read from codestudio with images

Largest Component

You are given an array 'ARR' of size 'N' containing positive integers. Consider an undirected graph using the given array with the following conditions:
-> The graph consists of 'N' vertices.
-> The ith vertex has a value 'ARR[i]'.
-> There is an edge between two vertices 'i' and 'j' (where 'i' < 'j'), if and only if GCD('ARR[i]', 'ARR[j]') is greater than 1.
GCD(a, b) is the maximum number x such that both a and b are divisible by x.
Your task is to find the size of the largest component in the graph.
A component of an undirected graph is a subgraph in which any two vertices are connected to each other by paths, and which is connected to no additional vertices in the rest of the graph. The size of a component is the number of vertices in it.
Input format :
The first line of input contains a single integer 'T', representing the number of test cases or queries to be run. 
Then the 'T' test cases are as follows.

The first line of each test case contains a positive integer 'N', which represents the size of the array 'ARR'.

The next line contains 'N' single space-separated positive integers representing the elements of the array.
Output Format :
For each test case, print an integer denoting the size of the largest component in the graph.
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints :
1 <= T <= 10
1 <= N <= 10^3
1 <= ARR[i] <= 10^5

Where 'ARR[i]' is the ith element in the array.

Time Limit: 1 sec
Sample Input 1:
1
6
10 4 2 5 3 9
Sample Output 1:
4
Explanation for Sample Input 1:
In the first test case, there are two components of size 4 and 2.
sample

Sample Input 2:
2
3
1 2 3
4
2 2 2 2
Sample Output 2:
1
4
Explanation for Sample Input 2:
In the first test case, there are three components and each is of size 1.
In the second test case, there is only one  components and it is of size 4.
*/


// Latest code by me : similar approach as below code, but much shorter and quicker
class DSU{  // DSU for maintaining all the prime factors graph
	vector<int> parent; 
	vector<int> setSize;
    vector<int> setElems; // this maintains a count of the number of elems from the input arr, which have prime factors belonging to a particular connected group of DSU

	public:
	DSU(int n){  // intially each prime-factor is its own parent
		for(int i=0; i<=n; i++) parent.push_back(i), setSize.push_back(1), setElems.push_back(0);
	}

	int root(int u){
		while(parent[u] != u){
			parent[u] = parent[parent[u]];
			u = parent[u];
		}

		return u;
	}

	int combine(int u, int v){
		int ru = root(u);
		int rv = root(v);

        int combinedRoot = rv;
		if(ru != rv){
			if(setSize[ru] > setSize[rv]){
				parent[rv] = ru;
				setSize[ru] += setSize[rv];
                setElems[ru] += setElems[rv];
                combinedRoot = ru;
			}
			else {
				parent[ru] = rv;
				setSize[rv] += setSize[ru];
                setElems[rv] += setElems[ru];
                combinedRoot = rv;
			}
		}

        return combinedRoot;
	}

    int getSetSize(int u) { return setSize[u]; }
    int getSetElems(int u) { return setElems[u]; }
    void increaseSetElems(int u) { setElems[u]++; }
};

int spf[100001];
bool spfDone = false;

void fillSpf(){
    for(int i=0; i<=100000; i++) spf[i] = i;

    for(int i=2; i*i <= 100000 ; i++){
        if(spf[i] == i){ // prime factor found
            for(int j = i*i; j<=100000; j+=i){
                if(spf[j] > i) spf[j] = i;
            }
        }
    }
}

int largestComponent(vector<int> &arr, int n){
    if (!spfDone) {
        fillSpf();
        spfDone = true;
    }

    DSU dsu = DSU(100000);  

    int ans = 1;
    for(int a : arr){
        if(a == 1) continue;  // dont connect 1 with anybody else, since 1 would always have gcd == 1 with everyone else
                                    // therefore dont make edge of 1 with anyone else
        
        int currRoot = dsu.root(spf[a]);

        a /= spf[a];
        while(a > 1){
            int grp = dsu.root(spf[a]);
            currRoot = dsu.combine(currRoot, grp);
            a /= spf[a];
        }

        dsu.increaseSetElems(currRoot);
        int currGrpElems = dsu.getSetElems(currRoot);
        if(currGrpElems > ans) ans = currGrpElems;
    }

    return ans;
}




#include<bits/stdc++.h>

vector<int> spf(100001, 0);
void fillSPF(){
    for(int i=0; i<=100000; i++) spf[i] = i;

    for(int i=2; i*i <= 100000; i++){
        if(spf[i] == i){  // means this is a prime number
            for(int j=i*i; j<=100000; j+=i){
                spf[j] = i;
            }
        }
    }
}

bool spfDone = false;

class DSU {
    vector<int> parent;
    vector<int> setSize;

    public:
    DSU(int n){
        for(int i=0; i<=n; i++){   // 1 based indexing from 1 to n
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

    int getSetSize(int u){
        return setSize[u];
    }

    void setSetSize(int root, int size){
        setSize[root] = size;
    }
};

int largestComponent(vector<int> &arr, int n){
    if(!spfDone) {
        fillSPF();
        spfDone = true;
    }

    vector<int> primeFactor_representative(100001, -1); // in this vector => if index i is a prime number => then primeFactor_representative[i] = a number from the given arr
                                                        // which contains i as a prime number in its prime factorisation 
    vector<int> numVisited(100001, 0); // maintaining a visited array, since duplicates nums can also be present in the input arr

    DSU dsu = DSU(100000); // preferring a vector of all the values inside the constraint range
                            // rather than building a unordered_map dsu containing only arr elements

    for(int i=0; i<n; i++){
        if(arr[i] == 1) continue;  // dont connect 1 with anybody else, since 1 would always have gcd == 1 with everyone else
                                    // therefore dont make edge of 1 with anyone else

        int num = arr[i];

        if(numVisited[num]){  // if this num is a duplicate , and already encountered before in the arr, then according to test cases we have to count duplicates individually
                              // so just increase the setSize to which this num belongs by 1
            int numRoot = dsu.findRoot(num);
            dsu.setSetSize(numRoot, dsu.getSetSize(numRoot) + 1);
            continue;
        }
        else{
            numVisited[num] = 1;
        }

        while(spf[num] > 1){  // doing prime factorisation of curr num, to go through all of its prime factors
            int primeFactor = spf[num];

            if(primeFactor_representative[primeFactor] == -1){
                primeFactor_representative[primeFactor] = arr[i];
            }
            else{
                // that means this primeFactor_representative and arr[i] would also have gcd > 1, 
                // so do dsu.combine which would check if they are already in same graph or not, and if not then would connect the 2 unconnected graphs
                dsu.combine(arr[i], primeFactor_representative[primeFactor]);
            }

            num /= primeFactor;
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        int num = arr[i];

        if(dsu.findRoot(num) == num){  // this means this num is a root of some connected component, and hence we can get its setSize
            int set_size = dsu.getSetSize(num);
            ans = ans > set_size ? ans : set_size;
        }
    }

    return ans;
}