/*
https://leetcode.com/problems/largest-rectangle-in-histogram/description/
*/


// this is the easier method which first comes to mind
// first do left to right iteration then reverse iteration of monotonic stack
class Solution {
public:
   int largestRectangleArea(vector<int>& heights) {
      int n = heights.size();
      vector<int> ans(n);
      stack<int> s;

      int end;
      for(int i=n-1; i>=0; i--) {
         while(!s.empty() && heights[s.top()] >= heights[i]) s.pop();

         if(s.empty()) end = n;
         else end = s.top();

         ans[i] = (end - i) * heights[i];
         s.push(i);
      }

      s = stack<int>();  // assigning a new empty stack
      int maxAns = INT_MIN;
      for(int i=0; i<n; i++) {
         while(!s.empty() && heights[s.top()] >= heights[i]) s.pop();

         if(s.empty()) end = -1;
         else end = s.top();

         ans[i] += (i - end - 1) * heights[i];
         if(maxAns < ans[i]) maxAns = ans[i];
         s.push(i);
      }

      return maxAns;
   }
};



/*
in this we do single left to right iteration only
about solution can be seen from neetcode or striver video
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // pair: [index, height]
        stack<pair<int, int>> stk;
        int result = 0;
        
        for (int i = 0; i < heights.size(); i++) {
            int start = i;
            
            while (!stk.empty() && stk.top().second > heights[i]) {
                int index = stk.top().first;
                int width = i - index;
                int height = stk.top().second;
                stk.pop();
                
                result = max(result, height * width);
                start = index;
            }
            
            stk.push({start, heights[i]});
        }
        
        while (!stk.empty()) {
            int width = heights.size() - stk.top().first;
            int height = stk.top().second;
            stk.pop();
            
            result = max(result, height * width);
        }
                          
        return result;
    }
};