/*
https://leetcode.com/problems/powx-n/description/
*/


class Solution {
private:
    double power(double x, long n) {
        double result = 1.0;
        while(n) {
            if(n%2) {
                result *= x;
            }

            x *= x;
            n /= 2;
        }

        return result;
    }

public:
    double myPow(double x, int n) {
        long exponent = abs(n);
        if(n < 0) {
            return 1 / power(x, exponent);
        }
        else return power(x, exponent);
    }
};