/*

*/


class Solution {
private:
    bool helper(vector<int>& piles, int &h, int k) {
        long long hours = 0;
        for(int pile : piles) {
            hours += (((pile-1)/k) + 1);
        }

        return hours <= h;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int i = 1, j = 1e9, mid;  // j = 1e9 , because the maximum koko can eat will be maximum possible height of a pile, which is 1e9 as per constraints
        int ans = j;
        while(i<=j) {
            mid = (i+j)/2;
            if(helper(piles, h, mid)) {
                if(mid < ans) ans = mid;
                j = mid-1;
            }
            else {
                i = mid+1;
            }
        }

        return ans;
    }
};