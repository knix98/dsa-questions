/*
https://leetcode.com/problems/happy-number/description/
*/


/*
    Detect cycle w/ slow/fast pointer technique
    If happy will eventually be 1, else pointers will meet

    Time: O(log n)
    Space: O(1)
*/

class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = getNext(n);
        
        // fast != 1 because once the sum of squares reaches 1 then it will be 1 only again and again
        while (slow != fast && fast != 1) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        
        if (fast == 1) {
            return true;
        }
        return false;
    }
private:
    int getNext(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            n /= 10;
            sum += pow(digit, 2);
        }
        return sum;
    }
};