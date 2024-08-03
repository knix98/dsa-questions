/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575426/offering/8882989/problem/10169?leftPanelTabValue=PROBLEM
*/



class DSU {
    vector<int> parent;
    vector<int> setSize;

    public:
    DSU(int n){
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

    int getSetSize(int u) { return setSize[u]; }
};

int countWays(int n, vector<vector<int>> &fruitIds)
{
	DSU dsu = DSU(n);

	for(auto v : fruitIds) dsu.combine(v[0], v[1]);

	vector<int> nums;
    vector<int> prefixSums;
    int prefixSum = 0;
	for(int i=0; i<n; i++) {
		if(dsu.findRoot(i) == i) {
			int num = dsu.getSetSize(i);
            nums.push_back(num);
            prefixSum += num;
            prefixSums.push_back(prefixSum);
		}
	}

    int s = nums.size();
    int ans = 0;
    for(int i=0; i<=s-2; i++){
        int add = nums[i] * (prefixSums[s-1] - prefixSums[i]);
        ans += add;
    }

	return ans;
}