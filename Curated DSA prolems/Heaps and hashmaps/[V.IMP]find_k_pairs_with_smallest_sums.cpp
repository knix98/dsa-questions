/*
https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/
*/


// Method 1 : without using map, only using priority_queue
vector<vector<int>> kSmallestPairs (vector<int> &arr1, vector<int> &arr2, int k)
{
    int n = arr1.size(), m = arr2.size();
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minpq;

    for(int i=0; i<min(n, k); i++){
        minpq.push({arr1[i] + arr2[0], i, 0});  // {sum, i, j}
    }

    vector<vector<int>> ans;
    while(ans.size() < k) {
        vector<int> top = minpq.top();
        minpq.pop();

        int i = top[1], j = top[2];
        ans.push_back({arr1[i], arr2[j]});

        // pushing the next possible pair w.r.t the current top pair
        if(j < m-1) minpq.push({arr1[i] + arr2[j+1], i, j+1});
    }

    return ans;
}



// Method 2 : using map for remembering which pairs have already been encountered
// for intuition and approach and time complexity, you can go and read the editorial tab of leetcode 
vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    int m = nums1.size();
    int n = nums2.size();

    vector<vector<int>> ans;
    set<pair<int, int>> visited;

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                    greater<pair<int, pair<int, int>>>> minHeap;
    minHeap.push({nums1[0] + nums2[0], {0, 0}});
    visited.insert({0, 0});

    while (k-- && !minHeap.empty()) {
        auto top = minHeap.top();
        minHeap.pop();
        int i = top.second.first;
        int j = top.second.second;

        ans.push_back({nums1[i], nums2[j]});

        if (i + 1 < m && visited.find({i + 1, j}) == visited.end()) {
            minHeap.push({nums1[i + 1] + nums2[j], {i + 1, j}});
            visited.insert({i + 1, j});
        }

        if (j + 1 < n && visited.find({i, j + 1}) == visited.end()) {
            minHeap.push({nums1[i] + nums2[j + 1], {i, j + 1}});
            visited.insert({i, j + 1});
        }
    }

    return ans;
}