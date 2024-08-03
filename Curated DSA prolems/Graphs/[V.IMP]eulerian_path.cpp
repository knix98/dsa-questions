/*
https://leetcode.com/problems/reconstruct-itinerary/description/ 
*/


/*
APPROACH 1 : Eulerian path, taken from pepcoding youtube channel
Notes about eulerian and hamiltonian paths written in DSA_notes.txt
And look at the second approach as well, because even though it has more time complexity, but its more intuitive and comes to mind first
*/
class Solution {
public:
	void dfs(unordered_map<string, priority_queue<string, vector<string>, greater<string>>> &graph, string curr, vector<string> &ans){
		while(!graph[curr].empty()){
            string next = graph[curr].top();
            graph[curr].pop();

            dfs(graph, next, ans);
        }

        ans.push_back(curr);
	}

    vector<string> findItinerary(vector<vector<string>>& tickets) {
		unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
		for(auto it : tickets){
			graph[it[0]].push(it[1]);
		}

		vector<string> ans;
		dfs(graph, "JFK", ans);
        reverse(ans.begin(), ans.end());
		return ans;
    }
};




/*
Approach 2 : taken from neetcode youtube
Basic approach is to do a DFS/backtracking over the graph and traverse all possible unidirectional paths and in the end
of these paths check whether all the edges have been travelled
NOTE : the challenging thing here is to keep track of which edge has been travelled already during recursion
For that I have used a unordered_set of string which stores an edge like this => a_b_1  (1 for differentiating multiple parallel edges between a and b)
And we are using a multiset for creating the graph because we want to visit the lexographically smaller nodes first
*/
class Solution {
public:
    unordered_set<string> visited_edges;

	bool dfs(unordered_map<string, multiset<string>> &graph, string curr, vector<string> &ans, int tickets){
		ans.push_back(curr);
		if(ans.size() == tickets + 1) return true;

		int i = 0;
		for(string next : graph[curr]){
			string edge = curr + "_" + next + "_" + (char)(i + (int)'0');
			if(visited_edges.find(edge) == visited_edges.end()){
				// means this edge is not visited
				visited_edges.insert(edge);
				if(dfs(graph, next, ans, tickets)) return true;
				visited_edges.erase(edge);
			}

			i++;
		}

		ans.pop_back();
		return false;
	}

    vector<string> findItinerary(vector<vector<string>>& tickets) {
		visited_edges.clear();
		unordered_map<string, multiset<string>> graph;
		for(auto it : tickets){
			graph[it[0]].insert(it[1]);
		}

		vector<string> ans;
		dfs(graph, "JFK", ans, tickets.size());
		return ans;
    }
};