/*
https://leetcode.com/problems/candy/description/

There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.

 

Example 1:

Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
Example 2:

Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.
 

Constraints:

n == ratings.length
1 <= n <= 2 * 104
0 <= ratings[i] <= 2 * 104
*/



// Explanation about the approach written in CN CP notes
// APPROACH : no of candies at index i depends only on candies at i+1 and i-1
// And we just need to ensure that among indexes a and b which are adjacent, the one with the higher grade should get 
// more candies, and if both the indexes grades are same then dont check anything
int requiredCandies(vector < int > &students) {
    int n = students.size();
    vector<int> ans(n, 1); // initially give 1 candy to every index

    // first traverse from left to right , checking every index with it's left index
    for(int i=1; i<n; i++){
        if(students[i-1] > students[i] && ans[i-1] <= ans[i]){
            ans[i-1] = ans[i] + 1;
        }
        if(students[i-1] < students[i] && ans[i-1] >= ans[i]){
            ans[i] = ans[i-1] + 1;
        }
    }

    // Now traverse from right to left , checking every index with it's right index
    for(int i=n-2; i>=0; i--){
        if(students[i+1] > students[i] && ans[i+1] <= ans[i]){
            ans[i+1] = ans[i] + 1;
        }
        if(students[i+1] < students[i] && ans[i+1] >= ans[i]){
            ans[i] = ans[i+1] + 1;
        }
    }

    int total = 0;
    for(int i=0; i<n; i++){
        total += ans[i];
    }

    return total;
}




// An APPROACH written by me in which I am identifying local peaks ( i-1 <= i >= i+1 ) and local minimas ( i-1 >= i <= i+1 )
// and placing 1 at every local minimas
// first find all minimas, maximas and normal points, then set values for minima and normal points first, then set maxima values in the end
int candy(vector<int>& s) {
    int n = s.size();
    if(n==1) return 1;
    
    int candy[n];

    // pc vector == position characteristic of every index i
    vector<char> pc(n, 'n');  // n means normal index
    
    // setting pc for i=0
    if(s[0] <= s[1]) pc[0] = 'm';  // m means minima
    else pc[0] = 'M';   // M means maxima
     
    // setting pc for i = n-1
    if(s[n-1] <= s[n-2]) pc[n-1] = 'm';
    else pc[n-1] = 'M';

    // finding all other minimas and maximas
    for(int i=1; i<n-1; i++){
        if(s[i] <= s[i-1] && s[i] <= s[i+1]) pc[i] = 'm';
        else if(s[i] >= s[i-1] && s[i] >= s[i+1]) pc[i] = 'M';
    }

    // setting 1 at minimas and setting values for normal indices
    for(int i=0; i<n; i++){
        if(pc[i] == 'm'){
            candy[i] = 1;

            // increasing set values for normal indices on either side of minima indices 
            int j = i+1;  
            while(j<n && pc[j] == 'n') candy[j] = candy[j-1] + 1, j++;

            j = i-1;
            while(j>=0 && pc[j] == 'n') candy[j] = candy[j+1] + 1, j--;
        }
    }

    // now since minimas and normals are set, only maximas are left
    int ans = 0;
    for(int i=0; i<n; i++){
        if(pc[i] == 'M'){
            // maxima's value = 1 + max(values of both the neighbours, if they exist and are set (means neighbour should not be another maxima))
            int maxNeighbour = INT_MIN;
            if(i+1 < n && pc[i+1] != 'M') maxNeighbour = max(maxNeighbour, candy[i+1]);            
            if(i-1 >= 0 && pc[i-1] != 'M') maxNeighbour = max(maxNeighbour, candy[i-1]);
            if(maxNeighbour > INT_MIN) candy[i] = maxNeighbour+1;
            else candy[i] = 1;  // this case is not possible though (that both the neighbours are maximas, in that case, i would be minima)
        }

        ans += candy[i];
    }

    return ans;
}