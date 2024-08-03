/*
24 Game

Ninja is feeling lonely, so he started playing online games. While searching for fun, he found an exciting game. In this game, Ninja has to choose four cards at random. On each card, there is a number between 1 to 9, both inclusive. For Ninja to win, he has to make the number 24 using the number on cards and the following operator *, /, +, -, (, ).
Help Ninja to find whether he will win the game or not, on the basis of his selection. If Ninja can win the game, print true otherwise, print false.
Example:-
If the cards Ninja chooses are 4, 1, 8, 7. Then Ninja can make 24 by (8 - 4) * (7 - 1). Hence Ninja can win, so you have to return true.
Note:-
The division operator ‘/’ represents actual division, not integer division. For example, 4 / (1 - ⅔ ) = 12.
Input Format:
The first line of input contains an integer ‘T’ denoting the number of test cases to run. Then the test case follows.

The next line of each test contains four space-separated integers denoting the cards which Ninja has.
Output Format:
For each test case, print true if Ninja can win the game; otherwise, print false.

Print the output of each test case in a separate file.
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:-
1 <= T <= 3000
1 <= NUMS[i] <= 9 where 0 <= i <= 4

Time Limit: 1 sec
Sample Input 1:-
2
4 1 8 7
1 2 1 2
Sample Output 1:-
True
False
Explanation Of Sample Input 1:-
Test case 1:- Here, we can make 24 by (8 - 4) * (7 - 1). Hence we will return true.

Test case 2:- Here, there is no way to make 24 using these cards, so ninja can’t win, hence return false.
Sample Input 2 :-
2
6 7 8 9
1 2 3 4
Sample Output 2:-
True
True 
Explanation Of Sample Input 2:-
Test case 1:- Here, we can make 24 by (8 - 4) * (7 - 1). Hence we will return true.

Test case 2:- Here, there is no way to make 24 using these cards, so ninja can’t win, hence return false.
*/



// here we will use brute force appoach only, since only four numbers and four operations if we calculate worst case time complexity,
// it comes out to be within 10^6
// Time : at each resursion call, selecting 2 nums from available set of nums and performing at max 6 operations on them
//        = (4^2 * 6) * (3^2 * 6) * (2^2 * 6) = O(124416) = O(10^5)
// Therefore Time = O(1), since everytime same number of operations , since every time 4 nums only
//           Space = O(1), since every time at max 4 recursive calls simultaeneously

// IMP : look at the base condition : this base condition is IMP in case we are dealing with flaoting point nums
/*
Since from chatgpt : 
The key point of concern here is how floating-point numbers are compared for equality, and this relates to the precision of floating-point arithmetic in computers. 
Floating-point numbers are approximations of real numbers and may not always represent real numbers exactly. 
As a result, comparing floating-point numbers directly using the equality operator (==) can lead to unexpected behavior and errors due to small differences in precision.

In your initial code, you had the following base case check:
if (abs(v[0] - 24.0) <= 0.00001)
    return true;

Here, you are checking if the absolute difference between v[0] (the final result) and 24.0 is less than or equal to a small epsilon value (0.00001). 
This approach is a common way to handle comparisons of floating-point numbers because it allows for a small margin of error due to precision issues.
*/
bool solve(vector<double> v){
    if(v.size() == 1){  // base case
        if(abs(v[0] - 24.0) <= 0.00001) return true;        
        // if(v[0] == 24) return true;
        return false;
    }


    for(int i=0; i<v.size(); i++){
        for(int j=i+1; j<v.size(); j++){
            vector<double> send;
            for(int k=0; k<v.size(); k++){
                if(k != i && k != j) send.push_back(v[k]);
            }

            send.push_back(v[i] + v[j]);
            if(solve(send)) return true;
            send.pop_back();

            send.push_back(v[i] - v[j]);
            if(solve(send)) return true;
            send.pop_back();

            send.push_back(v[j] - v[i]);
            if(solve(send)) return true;
            send.pop_back();

            send.push_back(v[i] * v[j]);
            if(solve(send)) return true;
            send.pop_back();

            if(v[j] != 0){
                send.push_back(v[i] / v[j]);
                if(solve(send)) return true;
                send.pop_back();
            }

            if(v[i] != 0){
                send.push_back(v[j] / v[i]);
                if(solve(send)) return true;
                send.pop_back();
            }
        }
    }

    return false;
}

bool judge(vector<int> &nums) {
    vector<double> v(nums.size());
    for(int i=0; i<nums.size(); i++) v[i] = (double)(nums[i]);

    return solve(v);
}