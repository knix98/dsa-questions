// Two Pointer approach
// METHOD 2 : time : O(n), space : O(1)
// can refer to takeuforward (striver) video
int trap(vector<int>& height) {
    int leftmax = 0, rightmax = 0;
    int l = 0, r = height.size() - 1;

    int ans = 0;
    while(l<r) {  // we dont need to consider case when l == r, because at this time, both l and r would be at some rightmax or leftmax
                // height itself, which will not contribute any ans to water
        
        if(height[l] <= height[r]) {
            if(height[l] >= leftmax) leftmax = height[l];
            else{
                // we are confidently able to use only leftmax for calculation of water at i, instead of min(leftmax, rightmax) because we know from the top "if condition" that,
                // i is only moving left if arr[i] <= arr[j]...so at any current i we can be sure that there would be a j on right such that arr[j] >= leftmax
                // so basically we can say that, if arr[j] is such that all the arr[i]s left to it are smaller than arr[j] => then j would always be fixed at that
                // position and i would keep on moving right, till a arr[i] comes such that it is greater than arr[j] and moves j leftwards
                ans += (leftmax - height[l]);
            }
            l++;
        }
        else {
            if(height[r] >= rightmax) rightmax = height[r];
            else{
                // similar logic as above here also
                ans += (rightmax - height[r]);
            }
            r--;
        }
    }

    return ans;
}