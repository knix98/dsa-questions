/*

QUESTION.....................

You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].
Now, in the given array/list, 'M' numbers are present twice and one number is present only once.
You need to find and return that number which is unique in the array/list.
 Note:
Unique element is always present in the array/list according to the given condition.

Sample Input 1:
2 3 1 6 3 6 2
Sample Output 1:
1

*/


//Best Method = XOR all the values

int findUnique(int *arr, int size){
    int ans = 0;
    for(int i=0; i<size; i++){
        ans ^= arr[i];
    }
    
    return ans;
}

/*

int findUnique(int *arr, int size)
{
    bool isUnique;
	for(int i=0;i<size;i++){
        isUnique = true;
        for(int j=0;j<size;j++){
            if(arr[i]==arr[j] && j!=i){
                isUnique = false;
                break;
            }
        }
        if(isUnique==true){
            return arr[i];
        }
    }
}

*/