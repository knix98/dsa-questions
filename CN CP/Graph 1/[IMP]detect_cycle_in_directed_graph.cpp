/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575410/offering/8882677/problem/8939

can read about this problem's solution in CN CP pdf notes
*/


bool cycleFound(vector<vector<int>> &graph, int node, vector<int> &nodeStatus){
	nodeStatus[node] = 1;  // starting the processing of current node

	for(int child : graph[node]){
		if(nodeStatus[child] == 1) {
			// means cycle found 
			return true;
		}
		if(nodeStatus[child] == 0){
			if(cycleFound(graph, child, nodeStatus)) return true;
		}

		// if nodeStatus[child] == 2, then dont do anything, because that child's recursion is already completed
	}

	nodeStatus[node] = 2;
	return false;
}

bool isCyclic(vector<vector<int>>& edges, int v, int e)
{
	vector<vector<int>> graph(v);
	for(vector<int> edge : edges){
		graph[edge[0]].push_back(edge[1]);
	}

	vector<int> nodeStatus(v, 0);  // status = 0 means not visited even once, 1 means under process in some recursion call, 2 means this node's recursion call is completed and returned back

	for(int i=0; i<v; i++){
		if(nodeStatus[i] == 0){
			if(cycleFound(graph, i, nodeStatus)) return true;
 		}
	}

	return false;
}
