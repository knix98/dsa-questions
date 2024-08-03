/*
Given an integer array of size N. Sort this array (in decreasing order) using heap sort.
Note: Space complexity should be O(1).
Constraints :
1 <= n <= 10^6
*/

void swap(int *arr, int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
	arr[b] = temp;
}

void heapSort(int arr[], int n) {
    // Write your code
    for(int i=1; i<n; i++){
        int newElement = i;
        int parent = (i-1)/2;
        while(newElement != 0 && arr[parent] > arr[newElement]){
            swap(arr, parent, newElement);
            newElement = parent;
            parent = (newElement-1)/2;
        }
    }
    
    for(int i=n-1; i>=1; i--){
        swap(arr, 0, i);
        int element = 0;
        while(2*element+1 < i){
            int min = element;
            if(arr[2*element+1] < arr[min]){
                min = 2*element+1;
            }
            if(2*element+2 < i && arr[2*element+2] < arr[min]){
                min = 2*element+2;
            }
            if(min == element){
                break;
            }
            swap(arr, element, min);
            element = min;
        }
    }
}