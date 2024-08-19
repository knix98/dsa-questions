/*
https://leetcode.com/problems/sliding-window-maximum/
*/

/*
    Given int array & sliding window size k, return max sliding window
    Ex. nums = [1,3,-1,-3,5,3,6,7] k = 3 -> [3,3,5,5,6,7]

    Sliding window deque, ensure monotonic decr, leftmost largest

    Time: O(n)
    Space: O(k)
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int k) {
        deque<int> dq;
        vector<int> ans;

        for(int i=0; i < v.size(); i++){
            while(!dq.empty() && v[dq.back()] <= v[i]){
                dq.pop_back();
            }
            
            dq.push_back(i);

            if(i >= k-1){
                while(dq.front() < i - k + 1){
                    dq.pop_front();
                }
                ans.push_back(v[dq.front()]);
            }
        }

        return ans;
    }
};