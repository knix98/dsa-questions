/*
https://leetcode.com/problems/find-median-from-data-stream/description/
*/



/*
    Implement data structure that gets the median from a data stream

    Max heap of lower values & min heap of higher values, access to mids

    Time: O(log n) + O(1)
    Space: O(n)
*/

// I implemented using multiset for practice and using begin and rbegin pointers
class MedianFinder {
private:
    multiset<int> left;
    multiset<int> right;

    void balance() {
        if(left.size() > right.size() + 1) {
            int largest = *left.rbegin();
            right.insert(largest);
            left.erase(left.find(largest));
        }
        else if(right.size() > left.size() + 1) {
            int smallest = *right.begin();
            left.insert(smallest);
            right.erase(right.find(smallest));
        }
    } 
 
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.empty()) {
            left.insert(num);
        }
        else {
            if(num <= *left.rbegin()) left.insert(num);
            else right.insert(num);
        }

        balance();
    }
    
    double findMedian() {
        if(left.size() == right.size()) {
            return (*left.rbegin() + *right.begin()) / 2.0;
        }
        else if(left.size() > right.size()) return *left.rbegin();
        else return *right.begin();
    }
};




// using priority_queue
class MedianFinder {
private:
    priority_queue<int> lower;
    priority_queue<int, vector<int>, greater<int>> higher;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (lower.empty()) {
            lower.push(num);
            return;
        }
        
        if (lower.size() > higher.size()) {
            if (lower.top() > num) {
                higher.push(lower.top());
                lower.pop();
                lower.push(num);
            } else {
                higher.push(num);
            }
        } else {
            if (num > higher.top()) {
                lower.push(higher.top());
                higher.pop();
                higher.push(num);
            } else {
                lower.push(num);
            }
        }
    }
    
    double findMedian() {
        double result = 0.0;
        
        if (lower.size() == higher.size()) {
            result = lower.top() + (higher.top() - lower.top()) / 2.0;
        } else {
            if (lower.size() > higher.size()) {
                result = lower.top();
            } else {
                result = higher.top();
            }
        }
        
        return result;
    }
};