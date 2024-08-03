/*
You are given with an integer k and an array of integers that contain numbers in random order. 
Write a program to find k smallest numbers from given array. You need to save them in an array and return it.
Time complexity should be O(n * logk) and space complexity should not be more than O(k).
Note: Order of elements in the output is not important.

NOTE : a similar question could ask you to find k largest numbers from given array
*/



//We can use a priority queue to keep sorting in each step and removing the max element and pushing the smaller element
//this has been done in first approach
//or we can simply use a vector only and keep sorting it using the sort algortihm
//this has been done in the second approach
//generally for this type of problems we prefer priority queue, because PQ takes care of sorting automatically,
//whereas in using vector we would have to sort from our side
#include<queue>
vector<int> kSmallest(int arr[], int n, int k) {
    // Write your code here
    priority_queue<int> pq;
    for(int i=0; i<k; i++){
        pq.push(arr[i]);
    }
    for(int i=k; i<n; i++){
        if(arr[i] < pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    
    vector<int> output;
    for(int i=1; i<=k; i++){
        output.push_back(pq.top());
        pq.pop();
    }
    
    return output;
}


//SECOND APPROACH.............................................................................................................
/*
vector<int> kSmallest(int arr[], int n, int k){
    vector<int> output;
    for(int i=0; i<k; i++){
        output.push_back(arr[i]);
    }
    sort(output.begin(), output.end());
    for(int i=k; i<n; i++){
        if(arr[i] < output[k-1]){
            output.pop_back();
            output.push_back(arr[i]);
            sort(output.begin(), output.end());
        }
    }
    
    return output;
}
*/