/*
https://leetcode.com/problems/car-fleet/description/
*/


/*
First code is a better space optimised approach, since we need to compare with only the 1 top element of the stack once only
so instead of stack we can keep maintaing the top element in a variable only
*/
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        set<pair<int,int>, greater<pair<int,int>>> s;   // i want to sort the positions of cars and their times based on the closest position first
                                                        // so sorting them in decreasing order
        
        for(int i=0; i<n; i++) s.insert({position[i], speed[i]});

        int time_of_closest_fleet_ahead = -1;
        int fleets = n;
        double time;
        for(auto p : s) {
            time = (double)(target - p.first) / p.second;  // time = time needed for this car to reach target
            
            // if the nearest ahead fleet's time is >= current car's time, then that means the curr car will catch this fleet and then move in this fleet only
            // that's why we need to compare with the nearest ahead fleet only
            if(time_of_closest_fleet_ahead != -1 && time_of_closest_fleet_ahead >= time) fleets--;  
            else time_of_closest_fleet_ahead = time;
        }

        return fleets;
    }
};


/*
Original code written by me : using stack
*/
class Solution {
public:
   int carFleet(int target, vector<int>& position, vector<int>& speed) {
      int n = position.size();
      set<pair<int,int>, greater<pair<int,int>>> s;   // i want to sort the positions of cars and their times based on the closest position first
                                                      // so sorting them in decreasing order
      
      for(int i=0; i<n; i++) s.insert({position[i], speed[i]});

      stack<double> st;
      double time;
      for(auto p : s) {
         time = (double)(target - p.first) / p.second;  // time = time needed for this car to reach target
         
         // if the nearest ahead car's time is >= current car's time, then that means the curr car will catch this car and then move in a fleet with this car only
         // that's why we need to compare with the nearest ahead car only
         if(!st.empty() && st.top() >= time) continue;  
         else st.push(time);
      }

      return st.size();
   }
};