#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    string stringMaker(int n) {
        string ans = "";
        int x;
        while(n) {
            x = n%10;
            n /= 10;

            ans += (x + '0');
        }

        return ans;
    }

    string slope(int x, int y) {
        if(x == 0) return "infinity";

        string slope = stringMaker(y) + "/" + stringMaker(x); 
        return slope;
    }
 
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        double slope;
        double X, Y;
        int infinity_slope = 0;

        for(int i=0; i<n; i++) {
            unordered_map<double, int> mp;
            infinity_slope = 0;
            for(int j = i+1; j<n; j++) {
                X = points[j][0] - points[i][0];
                Y = points[j][1] - points[i][1];
                
                if(X == 0) {
                    infinity_slope++;
                    ans = max(ans, infinity_slope);
                }
                else {
                    slope = Y/X;
                    mp[slope]++;
                    ans = max(ans, mp[slope]);
                }
            }
        }

        return ans;
    }
};