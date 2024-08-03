using namespace std;
#include <vector>

class PriorityQueue {
    vector<int> pq;

   public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMin() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin() {
        // Write your code here
        if (isEmpty()) {
            return 0;
        }
        
        int ans = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();
        int i=0;//i=index of the element which needs to be checked for it's correct position
        while(2*i + 1 < pq.size()){ //while left child exists, run the loop
            int min = i;//min=index of minimum element among parent and it's 2 children
            if(pq[2*i+1] < pq[i]){
                min = 2*i+1;
            }
            if(2*i+2 < pq.size() && pq[2*i+2]<pq[i] && pq[2*i+2]<pq[2*i+1]){//if right child exists and is smallest element
                min = 2*i+2;
            }
            if(min != i){
                int temp = pq[i];
                pq[i] = pq[min];
                pq[min] = temp;
                i=min;
            }
            else{ //is min==i, that means pq[i] is at correct position so break
                break;
            }
        }
        return ans;
    }
};