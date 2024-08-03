/*
CODE 1 : neetcode approach
problem link : https://leetcode.com/problems/minimum-interval-to-include-each-query/description/
*/
/*
    Given intervals array & queries array, ans to a query is min interval containing it
    Ex. intervals = [[1,4],[2,4],[3,6],[4,4]], queries = [2,3,4,5] -> [3,3,1,4]

    Min heap & sort by size of intervals, top will be min size, 

    Time: O(n log n + q log q) -> n = number of intervals, q = number of queries
    Space: O(n + q)
*/

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> sortedQueries = queries;
        
        // [size of interval, end of interval]
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // {query -> size of interval}
        unordered_map<int, int> m;
        
        // also need only valid intervals so sort by start time & sort queries
        sort(intervals.begin(), intervals.end());
        sort(sortedQueries.begin(), sortedQueries.end());
        
        vector<int> result;
        
        int i = 0;
        for (int j = 0; j < sortedQueries.size(); j++) {
            int query = sortedQueries[j];
            
            while (i < intervals.size() && intervals[i][0] <= query) {
                int left = intervals[i][0];
                int right = intervals[i][1];
                pq.push({right - left + 1, right});
                i++;
            }
            
            while (!pq.empty() && pq.top().second < query) {
                pq.pop();
            }
            
            if (!pq.empty()) {
                m[query] = pq.top().first;
            } else {
                m[query] = -1;
            }
        }
        
        for (int j = 0; j < queries.size(); j++) {
            result.push_back(m[queries[j]]);
        }
        return result;
    }
};




/*
CODE 2 : CN solution approach
problem link : https://classroom.codingninjas.com/app/classroom/me/11692/content/204440/offering/2653311/problem/14286?leftPanelTabValue=PROBLEM
*/
bool cmp(vector<int> &a, vector<int> &b){
    return (a[1] - a[0]) < (b[1] - b[0]);
}

vector<int> justiceLeague(vector<vector<int>>& intervals, vector<int>& codeNames) 
{
    map<int, vector<int>> mp;  // codename, indexes of this codename in the input vector
    for(int i=0; i<codeNames.size(); i++){
        mp[codeNames[i]].push_back(i);
    }

    sort(intervals.begin(), intervals.end(), cmp);
    
    vector<int> ans(codeNames.size(), -1);
    for(auto v : intervals){
        auto left = mp.lower_bound(v[0]);
        auto right = mp.upper_bound(v[1]);
        int length = v[1] - v[0] + 1;
        vector<int> eraseNodes;

        while(left != right){
            eraseNodes.push_back(left->first);
            for(int idx : left->second) ans[idx] = length;
            left++;
        }

        for(int i : eraseNodes) mp.erase(i);
    }

    return ans;
}