/*
Remainder Check

You just learnt about the “mod” operation and you’re fascinated by it. ‘X’ mod ‘Y’ is defined as the remainder that ‘X’ leaves when divided by ‘Y’.
You are now given two integers ‘X’ and ‘Y’ and ‘Q’ queries of the type ‘L’, ’R’ and you want to find the number of integers ‘T’ in the range (L , R) (both ‘L’ and ‘R’ included) such that
( ( T mod X ) mod Y ) ≠ ( ( T mod Y ) mod X ) 

For example:
If ‘X’=4 and ‘Y’=6, and the range is [1,7], then the answer will be 2, as both 6 and 7 satisfy the above condition. 

Input Format:
The first line contains 'T', denoting the number of test cases.
For each Test :
The first line contains three space-separated integers, ‘X’,’Y’ and ‘Q’.
The next ‘Q’ lines contain two integers each, ‘L’ and ‘R’.

Output Format:
For each query, print an one integer, representing the number of integers in that range satisfying the required condition.

Note:
You are not required to print the expected output. It has already been taken care of. Just implement the function.

Constraints -
1 <= 'T' <= 10
1 <= 'X',’Y’ <= 10^3
1 <= ‘Q’ <= 10^5 
1 <= ‘L’,’R’ <= 10^9

Note - The sum of 'Q' and ‘X’+’Y over all test cases does not exceed 10^5 and 2000 respectively.
Time Limit: 1 sec

Sample Input 1:
1
3 5 2
1 7
10 13
Sample Output 1
3
4
Explanation for Sample Input 1:
For test case 1:
    For query 1:
    The numbers 5,6 and 7 satisfy the required condition.

    For query 2:
    The numbers 10,11,12 and 13 satisfy the required condition.
Sample Input 2:
1
4 6 2
1 4
5 8
Sample Output 2:
0
3
*/



// read first explanation in hand notes then look at code.
// Also , for calculating lcm(x,y) = (x*y) / gcd(x,y)
int GCD(int a, int b){
    while(b > 0){
        int temp = a%b;
        a = b;
        b = temp;
    }

    return a;
}

int LCM(int a, int b){
    return (a / GCD(a,b)) * b;
}

int answersTillT(int t, int &period, vector<int> &periodAnswers){
    return ((t/period)*periodAnswers[period]) + periodAnswers[t%period];
}

vector<int> countValidNumbers(int x, int y, int q, vector<pair<int, int>> queries)
{
    vector<int> answers;    

    int period = LCM(x , y);
    vector<int> periodAnswers(period+1, 0);

    for(int i=1; i<=period; i++){
        if(((i % x) % y) != ((i % y) % x)) periodAnswers[i] = periodAnswers[i-1] + 1;
        else periodAnswers[i] = periodAnswers[i-1];
    }

    for(int i=0; i<q; i++){
        int l = queries[i].first;
        int r = queries[i].second;

        answers.push_back(answersTillT(r, period, periodAnswers) - answersTillT(l-1, period, periodAnswers));
    }

    return answers;
}