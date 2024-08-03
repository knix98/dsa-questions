/*
It can be solved using map data structure in nlogn time 
But to do it in n time, we can decide to store the frequency of elems in a normal vector instead of map
becuase the size of the vector would be bounded by the max_frequency of any element
*/


vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> fq; 

    // first just store fq of each distinct int
    int max_fq = 0;
    for(int i : nums) {
        fq[i]++;
        if(fq[i] > max_fq) max_fq = fq[i];
    }

    vector<vector<int>> v(max_fq + 1);   // v[i] would contain all those distinct ints which have fq as i in the input array
    for(auto i : fq){
        v[i.second].push_back(i.first);
    }

    vector<int> ans;
    int i = max_fq;
    while(k > 0){
        for(int j : v[i]) {
            ans.push_back(j);
            k--;
            if(k == 0) return ans;
        }
        i--;
    }

    // return ans;
} 