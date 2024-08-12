/*
https://leetcode.com/problems/max-points-on-a-line/description/
*/



/*
Intuition
If two points lie on the same line, the slope (y2-y1)/(x2-x1) is same;

Approach
we calculate slope of all points from a given point and in hashmap , we store the frequency of those slopes that would give us the no. of points on that line;
Note: The testcases also contain same points multiple times too so need to accomodate them and we add them to each and every slope we calculate
*/
class Solution {
public:
    int maxPoints(vector<vector<int>>& v) {
        double slope;
        int n=v.size();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<double,int> m;
            double x,y;
            int ma=0;    // maximum count of a slope in the map
            int same=1;  // count of number of points that coinicide with the point at index i (our main point)
            int infinity_slope = 0;
            for(int j=i+1;j<n;j++){
                if(v[i][0]==v[j][0]&&v[i][1]==v[j][1]){
                    same++;
                    continue;
                }
                x=v[i][0]-v[j][0];
                y=v[i][1]-v[j][1];
                if(x==0){
                    infinity_slope++;
                    ma = max(ma, infinity_slope);
                }
                else{
                    slope=y/x;
                    m[slope]++;
                    ma = max(ma, m[slope]);
                }
            }
            ans=max(ma+same,ans);   // since the number of points on a line with slope x = ma[x] + (number of main points)
        } 
        return ans;
    }
};