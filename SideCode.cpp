#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int maxCoins(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> dp(n, vector<int>(n, 0));

//         int ls, le, rs, re, check;
//         for(int i=n-1; i>=0; i--) {
//             dp[i][i] = nums[i];
//             if(i > 0) dp[i][i] *= nums[i-1];
//             if(i < n-1) dp[i][i] *= nums[i+1];
//             // dp[curr][i] = nums[i];
//             // if(i > 0) dp[curr][i] *= nums[i-1];
//             // if(i < n-1) dp[curr][i] *= nums[i+1];

//             for(int j=i+1; j<n; j++) {
//                 dp[i][j] = 0;
//                 // dp[curr][j] = 0;

//                 for(int k=i; k<=j; k++) {
//                     ls = i, le = k-1, rs = k+1, re = j;
//                     check = nums[k];
//                     if(ls <= le) check += dp[ls][le];
//                     if(rs <= re) check += dp[rs][re];

//                     dp[i][j] = max(dp[i][j], check);
//                 } 
//             }
//         }

//         for(int i=0; i<n; i++) {
//             for(int j=0; j<n; j++) {
//                 cout << dp[i][j] << " ";
//             }
//             cout << endl;
//         }

//         return dp[0][n-1];
//     }
// };

long long maximumSum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<vector<long long>> dp(n+1, vector<long long>(k+1, -9));

    for(int i=0; i<n+1; i++) dp[i][0] = 0;

    long long ans = -9;

    for(int i=n-1; i>=0; i--) {
        for(int j=1; j<=k; j++) {
            dp[i][j] = -9;

            for(int t = i+1; t<n+1; t++) {
                if((t == n || nums[t] >= nums[i]) && dp[t][j-1] > -9) {
                    dp[i][j] = max(dp[i][j], nums[i] + dp[t][j-1]);
                } 
            }
        }

        ans = max(ans, dp[i][k]);
    }

    for(int i=0; i<n+1; i++) {
        for(int j=0; j<k+1; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return ans;
}

class Solution {
private:
    int k;
    int target;

    bool helper(vector<int>& nums, int i, vector<bool> &available, int bucketNo, int bucketSum) {
        if(bucketSum == target) {
            // start filling a new bucket from the first index of nums
            bucketNo++;
            bucketSum = 0;
            i=0;
        }
        if(bucketNo == k) return true; // means we have filled k-1 buckets with targetSum, so we are done
        if(i == nums.size()) {
            // means we have reached end of nums without successfully making up targetSum in the current bucket (i.e bucketSum < target)
            return false;
        }

        // for(int i=0; i<available.size(); i++) {
        //     if(available[i] && bucketSum + nums[i] <= target) {
        //         available[i] = false;
        //         if(helper(nums, i+1, available, bucketNo, bucketSum + nums[i])) return true;
        //         available[i] = true;
        //     }
        // }

        // return false;

        if(available[i]) {
            // case 1 try taking curr elem
            if(bucketSum + nums[i] <= target) {
                available[i] = false;
                if(helper(nums, i+1, available, bucketNo, bucketSum + nums[i])) return true;
                available[i] = true;
            }
        }

        // case 2 leave curr elem
        return helper(nums, i+1, available, bucketNo, bucketSum);    
    }

public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        vector<bool> available(nums.size(), true);
        this->k = k;

        target = 0;
        for(int i : nums) target += i;
        if(target % k) return false;
        target /= k;

        return helper(nums, 0, available, 1, 0);
    }
};

void palindromeDP(vector<vector<bool>> &isPalindrome, string &s) {
	for(int i=s.size()-2; i>=0; i--) {
		for(int j=i+1; j<s.size(); j++) {
			if(s[i] == s[j] && isPalindrome[i+1][j-1]) isPalindrome[i][j] = true;
			else isPalindrome[i][j] = false;
		}
	}
}

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        int ans = 1;

        for(int i=0; i<n; i++) {
            for(int j=n-1; j>=i; j--) {
                if(s[i] == s[j]) {
                    if(i == j) {
                        if(i > 0) dp[i][j] = 1 + dp[i-1][j+1];
                        else dp[i][j] = 1;
                    }
                    else {
                        if(i > 0) dp[i][j] = 2 + dp[i-1][j+1];
                        else dp[i][j] = 2;
                    }
                }
                else {
                    // the same lcs approach : max([i][j+1], [i-1][j])
                    dp[i][j] = dp[i][j+1];
                    if(i > 0) dp[i][j] = max(dp[i][j], dp[i-1][j]);
                }

                ans = max(ans, dp[i][j]);
            }
        }

        return ans;
    }
};

class Solution {
private:
    bool helper(string &s, string &p, int si, int pi, char prev) {
        if(si >= s.size()) return true;
        else if(pi >= p.size()) return false;
        
        // assuming pi and si are valid
        if(p[pi] == '.') {
            return helper(s, p, si+1, pi+1, '.');
        }
        else if(p[pi] == '*') {
            if(prev == '.') {
                return helper(s, p, si+1, pi, '.');
            }
            else {
                // means here prev is an alphabet
                if(prev == s[si]) return helper(s, p, si+1, pi, s[si]);
                else return helper(s, p, si, pi+1, prev);
            }
        }
        else {
            // means here p[pi] is an alphabet
            if(p[pi] == s[si]) return helper(s, p, si+1, pi+1, s[si]);
            else return false;
        }
    }

public:
    bool isMatch(string s, string p) {
        return helper(s, p, 0, 0, '');
    }
};








int longestRepeatingSubsequence(string st, int n)
{
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    int ans = 0;

    for(int i=n-2; i>=0; i--) {
        for(int j=n-1; j>i; j--) {
            if(st[i] == st[j]) {
                dp[i][j] = 1 + dp[i+1][j+1];
            }
            else {
                dp[i][j] = max(dp[i][j], dp[i][j+1]);
                dp[i][j] = max(dp[i][j], dp[i+1][j]);
                dp[i][j] = max(dp[i][j], dp[i+1][j+1]);
            }

            ans = max(ans, dp[i][j]);
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return ans;
}

class Solution {
public:
    bool solver(vector<int>& nums, vector<int>& visited, int start_index, int k, int current_sum, int target) {
        if (k == 0) return true;  
        if (current_sum == target) {
            
            return solver(nums, visited, 0, k - 1, 0, target);
        }

        for (int i = start_index; i < nums.size(); i++) {
            if (!visited[i] && current_sum + nums[i] <= target) {
                visited[i] = 1;  
                if (solver(nums, visited, i + 1, k, current_sum + nums[i], target)) {
                    return true;
                }
                visited[i] = 0;  
               if (current_sum == 0)
                    return false;
            }
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;  

        int target = sum / k;
        vector<int> visited(nums.size(), 0);
        sort(nums.begin(), nums.end(), greater<int>()); 
        return solver(nums, visited, 0, k, 0, target);
    }
};

class Solution {
    public boolean canPartitionKSubsets(int[] nums, int k) {
        int sum = Arrays.stream(nums).sum();
        if (sum % k != 0) return false;
        
        int targetSum = sum / k;
        Arrays.sort(nums);
        // add a reverse it helps!
        return backtrack(nums.length - 1, nums, new int[k], targetSum);
    }
    
    private boolean backtrack(int index, int[] nums, int[] sums, int targetSum) {
        if (index < 0) return true;
        
        for (int i = 0; i < sums.length; i++) {
            if (sums[i] + nums[index] > targetSum) continue;
            
            sums[i] += nums[index];
            
            if (backtrack(index - 1, nums, sums, targetSum)) {
                return true;
            }
            
            sums[i] -= nums[index];
            
            if (sums[i] == 0) break;// why ? explanation given below
        }
        
        return false;
    }
}
/*
Great question! The line if (sums[i] == 0) break; is indeed a crucial optimization that can significantly reduce the time complexity in many cases. Let's break down why this is so effective:

Avoiding Duplicate Work:
When we backtrack and remove a number from a subset, if that subset becomes empty (sum becomes 0), it means we're back to the starting point for that subset. If we continue to the next iteration of the loop, we'd be trying to add the current number to another empty subset. This would lead to exploring the same combinations we've already explored or will explore in future recursive calls.
Symmetry Breaking:
All empty subsets are identical from the perspective of our algorithm. Once we've tried adding the current number to one empty subset and it didn't lead to a solution, there's no point in trying to add it to other empty subsets.
Pruning the Search Tree:
By breaking the loop when we encounter an empty subset, we're effectively pruning a large portion of the search tree. This can drastically reduce the number of recursive calls and iterations.
Reducing Permutations:
Without this break, the algorithm would consider all permutations of the subsets, which is unnecessary since we only care about the content of the subsets, not their order.

Time Complexity Impact:

In the worst case (when no valid partition exists), the time complexity without this optimization could be O(k^n), where k is the number of subsets and n is the number of elements.
With this optimization, many redundant paths are eliminated, potentially reducing the time complexity significantly, although it remains exponential in the worst case.

Practical Impact:

For inputs where many valid solutions exist, this optimization might not make a huge difference.
However, for inputs where valid solutions are sparse or non-existent, this optimization can reduce the runtime from hours or days to seconds or minutes.

Example:
Consider an array [10, 10, 10, 7, 7, 7, 6, 6, 6] with k = 3. Without the optimization, the algorithm would try many permutations of how to distribute these numbers. With the optimization, once it tries [10, 10, 10] in one subset and backtracks, it immediately knows not to try 10 in the other empty subsets, significantly reducing the search space.
In summary, this simple optimization leverages the problem's structure to eliminate a vast number of unnecessary recursive calls, making the algorithm much more efficient in practice, especially for challenging inputs.
*/

int main() {
    cout << longestRepeatingSubsequence("BCCB", 4);
}