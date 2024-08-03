/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575391/offering/8882340/problem/12894?leftPanelTabValue=PROBLEM

You are given a stream of tuples which constitute three things ‘Key’, ‘Val’, and the ‘Timestamp’.

Your task is to implement the ‘TimeBased’ class having the two functions:

1) The first function is ‘setKey(string Key, string Val, int Timestamp)’, which stores the ‘Key’ and the ‘Val’ along with the ‘Timestamp’.

2) The second function is ‘getValue(string TargetKey, int TargetTimestamp)’, which returns the value of ‘Val’ associated with the ‘TargetKey’ such that its ‘Timestamp’ value is less than or equal to the ‘TargetTimestamp’. If there are multiple values of ‘Val’, return the value of ‘Val’ with the highest value of ‘Timestamp’ among the valid ones. If there is no valid value of ‘Val’ return “-1” as a string.
‘Timestamps’ will always be in strictly increasing order.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 3 * 10^4
1 <= | Val |, | Key | <= 10
1 <= Timestamp <= 10^7

Where ‘T’ represents the number of test cases, ‘N’ represents the number of queries, ‘Val’, ‘Key’ and ‘Timestamp’ are added to the stream.


Time Limit: 1 sec
Sample Input 1:
 2
 4
 1 abc def 10
 1 abc ghi 20
 2 abc 10
 2 abc 5
 3
 1 bbb ccc 5
 1 ddd ccc 5
 2 ddd 6 
Sample Output 1:
 def  -1
 ccc
Explanation For sample Input 1:
For the first test case, 
First, “abc” is added as a key and “def” as a value, and 10 as a timestamp. So at this moment, we have a single data, i.e. {“abc”, “def”, 10}. Then again, “abc” is added as a key along with “ghi” as a value and 20 as the timestamp. Now we have two records, i.e. {“abc”, “ghi”, 20} and {“abc”, “def”, 10}. Now query of type 2 is called, and we have to find the value of ‘Val’ such that its key is “abc” and its timestamp value should be less than or equal to the target timestamp ‘TargetTimestamp’ i.e 10. So the output for this query is “def”. Now again, the query of type 2 is called, and we have to find the value of ‘Val’ such that its key is “abc” and its timestamp value should be less than or equal to the target timestamp ‘TargetTimestamp’ i.e 5. So the output for this query is “-1” as there exists no value of timestamp, which is less than or equal to 5. 

For the second test case, 
First, “bbb” is added as a key along with “ccc” as a value and 5 as a timestamp. So at this moment, we have a single data, i.e. {“bbb”, “ccc”, 5}. Then again, the query of type 1 is executed, and “ddd” is added as a key along with “ccc” as value and 5 as a timestamp. Now we have two records, i.e. {“bbb”, “ccc”, 5} and {“ddd”, “ccc”, 5}. Now query of type 2 is called, and we have to find the value of ‘Val’ such that its key is “ddd” and its timestamp value should be less than or equal to target timestamp ‘TargetTimestamp’ i.e 6. So the output for this query is “ccc”. 
Sample Input 2:
2
3
1 yyy zzz 3
1 yyy xxx 4
2 yyy 4
4
2 fff 13
1 fff ggg 13
1 fff hhh 14
2 fff 14 
Sample Output 2:
xxx
-1 hhh
Explanation For Sample Input 2:
For the first test case, 
First, “yyy” is added as a key and “zzz” as a value, and 3 as a timestamp. So at this moment, we have a single data, i.e. {“yyy”, “zzz”, 3}. Then again, “yyy” is added as a key along with “xxx” as a value and 4 as the timestamp. Now we have two records, i.e. {“yyy”, “zzz”, 3} and {“yyy”, “xxx”, 4}. Now query of type 2 is called, and we have to find the value of ‘yyy’ such that its key is “yyy” and its timestamp value should be less than or equal to the target timestamp ‘TargetTimestamp’ i.e 4. So the output for this query is “xxx”.

For the second test case, 
Initially, no data is present so for query 2, the output will be -1. First, “fff” is added as a key along with “ggg” as a value and 13 as a timestamp. So at this moment, we have a single data, i.e. {“fff”, “ggg”, 13}. Then again, the query of type 1 is executed, and “fff” is added as a key along with “hhh” as value and 14 as a timestamp. Now we have two records, i.e. {“fff”, “ggg”, 13} and {“fff”, “hhh”, 14}. Now query of type 2 is called, and we have to find the value of ‘fff’ such that its key is “fff” and its timestamp value should be less than or equal to target timestamp ‘TargetTimestamp’ i.e 14. So the output for this query is “hhh”. 
*/



/*
    Your Timebased object will be instantiated and called as such:

    Timebased* obj = new Timebased();
    obj->setKey(key,value,timestamp);
    string ans = obj->getValue(targetKey,targetTimestamp);
*/
#include<bits/stdc++.h>


class Timebased {
    unordered_map<string, map<int, string, greater<int>>> mp; // creating the inside map a descending map
    // because we want to get the the timestamp which is equal or just lesser than the targetTimestamp
    // so lower_bound() on a descending sort of keys of map , would return us the value which is equal to or just lesser than 
    // the targetTimestamp
 
    public:
        Timebased() {
            // Intialise your data structure here.
        }

    void setKey(string key, string val, int timestamp) {
        mp[key][timestamp] = val;        
    }

    string getValue(string targetKey, int targetTimestamp) {
        auto it = mp[targetKey].lower_bound(targetTimestamp);

        if(it == mp[targetKey].end()) return "-1";

        return it->second;
    }
};