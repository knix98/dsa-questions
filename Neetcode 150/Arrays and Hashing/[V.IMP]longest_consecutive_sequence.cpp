// Method 1 : neetcode approach
// Time : O(n) since every elem in unordered_set visited atmost twice (once during normal while loop and another during operation of finding length of any sequence)
// Space : O(n)
int longestConsecutive(vector<int>& nums) {
    // first create a set of distinct elems from nums array
    // distinct elems because we just need to find consecutive sequence length, so dont need to consider duplicate elems
    unordered_set<int> s(nums.begin(), nums.end());

    int ans = 0;
    for(int i : s) {
        if(!s.count(i-1)){
            // means i must be a starting elem of any consecutive seq, since i-1 is not there in nums

            // so now find all elems in nums which come in consecutive sequence to i
            int j = i;
            while(s.count(j+1)) j++;

            if(ans < j-i+1) ans = j-i+1;
        }
    }

    return ans;
}



// Method 2 : my thought out approach using unordered_map ... basically its a DSU like approach only for combining consecutive elems together
// Time : O(n)
int longestConsecutive(vector<int>& nums) {
    unordered_map<int,int> ends;  // if there is a sequence 2,3,4 then in ends I would store => ends[2] = 4, ends[4] = 2;
                                  // so that both 2 and 4 could be found out

    int endleft, endright, ans = 0, erase1, erase2;
    for(int i : nums) {
        if(ends.find(i) != ends.end()) continue;  // means ignore duplicate elems

        endleft = endright = i;  // we will try to find the ends of the sequence in which this i fits in (with the current sets of ends present in the map (DSU like approach))
        
        auto left = ends.find(i-1);
        if(left != ends.end()) {
            endleft = min({endleft, left->first, left->second});
            endright = max({endright, left->first, left->second});
            erase1 = left->first, erase2 = left->second;  // erase the previous ends , since new ends would be inserted in map, in later code (see below)
            ends.erase(erase1);
            ends.erase(erase2);
        }

        auto right = ends.find(i+1);
        if(right != ends.end()) {
            endleft = min({endleft, right->first, right->second});
            endright = max({endright, right->first, right->second});
            erase1 = right->first, erase2 = right->second;
            ends.erase(erase1);
            ends.erase(erase2);
        }

        ends[endleft] = endright;
        ends[endright] = endleft;
        if(abs(endright - endleft) + 1 > ans) ans = abs(endright - endleft) + 1;
    }

    return ans;
}