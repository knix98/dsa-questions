/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575426/offering/8882969/problem/8945
*/


bool test(vector<vector<int>> &edges, vector<bool> &visited, vector<int> &nodeColor, int i, int color) {
	visited[i] = true;
	nodeColor[i] = color;

	for(int j=0; j<edges[i].size(); j++){
		if(edges[i][j]){
			if(visited[j]){
				if(color == nodeColor[j]) return false;
			}
			else{
				if(!test(edges, visited, nodeColor, j, color^1)) return false;
			}
		}
	}

	return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
	vector<bool> visited(edges.size(), false);
	vector<int> nodeColor(edges.size());

	for(int i=0; i<edges.size(); i++){
		if(!visited[i]){
			bool smallAns = test(edges, visited, nodeColor, i, 0);
			if(smallAns == false) return false;
		}
	}

	return true;
}