/*
This question is on codestudio by the same name - can have look there at the question

Number of operations to make Graph connected.

You have been given a graph consisting of ‘N’ vertices numbered from 1 to ‘N’. The graph has ‘M’ edges. In an operation, you can shift an edge between two directly connected vertices to between pair of disconnected vertices to make them directly connected. Return the minimum number of operations to make the graph connected. If it is not possible to make graph connected return -1.
Example:
Let’s say ‘N’ is 4 and ‘M' is 3. The 3 edges are (1,2), (2,3) and (1,3). Then our graph will look as follows:-
subsequence

To make the graph connected we can shift the edge between (1,3) to (1,4). This operation will make the graph connected. There are multiple ways in which we can make graph connected. So, in this case, we can make graph connected in just one operation.
Note:
1. A connected graph is a graph that is connected in the sense of a topological space, i.e., there is a path from any vertex to any other vertex in the graph.

2. There are no repeated edges and self-loops in the graph.

3. You do not need to print anything; it has already been taken care of. Just implement the function.
Input Format:
The first line contains a single integer ‘T’ representing the number of test cases.

The first line of each test case contains two space-separated integers ‘N’ and ‘M’ representing the number of vertices and the number of edges in the graph.

Each of the next ‘M’ lines contains two space-separated integers representing the vertices that are directly connected by an edge.
Output Format:
For each test case, print a single line containing a single integer denoting the minimum number of operations to make the graph connected. If it is not possible to make graph connected return -1.

The output of each test case will be printed in a separate line.
Note:
You do not need to input or print anything, as it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 10
1 <= N <= 10000
1 <= M <= 10000
1 <= U[i], V[i] <= N

Where ‘T’ is the number of test cases.‘N’ is the number of vertices in the graph. ‘M’ is the number of edges in the graph. ‘U[i]’ and ‘V[i]’ are vertices of the i-th edge.

Time Limit: 1sec.
Sample Input 1:
2
4 3
1 2
2 3
3 1
4 3
1 2
2 3
3 4
Sample Output 1:
1
0
Sample Output 1 Explanation:
Test case 1:

The graph looks as follows:-
subsequence

Initially, graph is disconnected. We can apply one operation and shift the edge between (2,3) to (3,4). This operation will make the graph connected. The graph after the operation will look as follows:-
subsequence

Therefore the answer is 1.


Test case 2:

The graph looks as follows:-
subsequence

The graph is already connected so we don’t need to make any operation.

Therefore the answer is 0.
Sample Input 2:
2
4 2
1 2
3 4
4 6
1 2
1 3
1 4
2 3
2 4
3 4
Sample Output 2:
-1
0 
*/



//better approach...
/*
    Time Complexity: O(N + M)  
    Space Complexity: O(N)
    
    Where N is the total number of nodes and M is total number of edges
*/

int parent[10005];
int s[10005];

int root(int a) 
{
  if (a == parent[a]) 
  {
    return a;
  }

  return parent[a] = root(parent[a]);
}

void dsunion(int a, int b) 
{
  a = root(a);
  b = root(b);

  if (a != b) 
  {
    if (s[a] < s[b])
      swap(a, b);

    parent[b] = a;
    s[a] += s[b];
  }
}

int makeGraphConnected(int n, vector < pair < int, int > > edges, int m) 
{
      // for having a connected graph, minimum number of edges required are n-1
      if (m < n - 1) 
      {
        return -1;
      }

      // now we just need to count the total number of sets here, and then the answer would be simply (sets-1) edges required to connect them
      int ans = n;
      for (int i = 1; i <= n; i++) 
      {
        parent[i] = i;
        s[i] = 1;
      }

      for (int i = 0; i < m; i++) {
        if (root(edges[i].first) != root(edges[i].second)) 
        {
          dsunion(edges[i].first, edges[i].second);
          ans--;
        }
      }

      return (ans - 1);
}