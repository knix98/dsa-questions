/*
Implement the class for Max Priority Queue which includes following functions -
1. getSize -
Return the size of priority queue i.e. number of elements present in the priority queue.
2. isEmpty -
Check if priority queue is empty or not. Return true or false accordingly.
3. insert -
Given an element, insert that element in the priority queue at the correct position.
4. getMax -
Return the maximum element present in the priority queue without deleting. Return -Infinity if priority queue is empty.
5. removeMax -
Delete and return the maximum element present in the priority queue. Return -Infinity if priority queue is empty.
*/

using namespace std;
#include<vector>
#include<climits>
class PriorityQueue {
    // Declare the data members here
    vector<int> pq;

   public:
    PriorityQueue() {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        // Implement the insert() function here
        pq.push_back(element);
        int i = pq.size()-1;
        int parent = (i-1)/2;
        while(i != 0 && pq[parent] < pq[i]){
            int temp = pq[i];
            pq[i] = pq[parent];
            pq[parent] = temp;
            i = parent;
            parent = (i-1)/2;
        }
    }

    int getMax() {
        // Implement the getMax() function here
        if(isEmpty()){
            return INT_MIN;
        }
        else{
            return pq[0];
        }
    }

    int removeMax() {
        // Implement the removeMax() function here
        if(isEmpty()){
            return INT_MIN;
        }
        int ans = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();
        int i=0;
        while(2*i+1 < pq.size()){
            int max = i;
            if(pq[2*i+1] > pq[i]){
                max = 2*i+1;
            }
            if(2*i+2 < pq.size() && pq[2*i+2] > pq[i] && pq[2*i+2] > pq[2*i+1]){
                max = 2*i+2;
            }
            if(max == i){
                break;
            }
            int temp = pq[i];
            pq[i] = pq[max];
            pq[max] = temp;
            i = max;
        }
        return ans;
    }

    int getSize() { 
        // Implement the getSize() function here
        return pq.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here
        return pq.size()==0 ? true : false;
    }
};