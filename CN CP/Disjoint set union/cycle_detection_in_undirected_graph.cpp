/*
Cycle Detection In Undirected Graph

You have been given an undirected graph with 'N' vertices and 'M' edges. The vertices are labelled from 1 to 'N'.
Your task is to find if the graph contains a cycle or not.
A path that starts from a given vertex and ends at the same vertex traversing the edges only once is called a cycle.
Example :
In the below graph, there exists a cycle between vertex 1, 2 and 3. 
Example

Note:
1. There are no parallel edges between two vertices.

2. There are no self-loops(an edge connecting the vertex to itself) in the graph.

3. The graph can be disconnected.
For Example :
Input: N = 3 , Edges =  [[1, 2], [2, 3], [1, 3]].
Output: Yes

Explanation : There are a total of 3 vertices in the graph. There is an edge between vertex 1 and 2, vertex 2 and 3 and vertex 1 and 3. So, there exists a cycle in the graph. 
Input Format:
The first line of input contains an integer 'T' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case contains two single space-separated integers ‘N’ and ‘M’ representing the total number of vertices and edges, respectively.

The next ‘M’ lines contain two single space-separated integers representing an edge of the graph.
Output Format:
For each test case, the only line of output will return “Yes” if there exists a cycle in the graph. Else print “No”.
Note:
You are not required to print the expected output, it has already been taken care of. Just implement the function.
Constraints:
1 <= T <= 10
1 <= N <= 5000
0 <= M <= min(5000, (N * (N - 1)) / 2)
1 <= edges[i][0] <= N 
1 <= edges[i][1] <= N 

Time Limit: 1 sec 
Sample Input 1:
1
3 2
1 2
2 3
Sample output 1:
No
Explanation of Sample output 1:
 The above graph can be represented as 
Example

There are a total of 3 vertices in the graph.There is an edge between vertex 1 and 2 and vertex 2 and 3. So, there is no cycle present in the graph. 
Sample Input 2:
2
4 0 
4 3
1 4
4 3
3 1
Sample output 2:
No
Yes
*/




int findRoot(vector<int> &parent, int u){
    while(u != parent[u]){
        parent[u] = parent[parent[u]];
        u = parent[u];
    }

    return u;
}

void combine(vector<int> &parent, vector<int> &setSize, int ru, int rv){
    // comine the smaller set to larger set
    // or make the parent as the one with the larger setSize
    if(setSize[ru] > setSize[rv]){
        parent[rv] = ru;
        setSize[ru] += setSize[rv];
    }
    else{
        parent[ru] = rv;
        setSize[rv] += setSize[ru];
    }
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // DSU algorithm
    vector<int> parent(n+1, 0);   // using 1 based indexing for vertices 1 to n
    for(int i=1; i<=n; i++) parent[i] = i;

    vector<int> setSize(n+1, 1);

    for(int i=0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        // first find the roots of u and v
        int ru = findRoot(parent, u);
        int rv = findRoot(parent, v);

        if(ru == rv){
            // means u and v already belonged to the same set, and now we are asking to make an edge btw them
            // or, a path from u to v already existed, and now we are making a direct edge between them
            // so its sure that a cycle is going to form here
            return "Yes";
        }
        else{
            combine(parent, setSize, ru, rv);
        }
    }

    return "No";
}




