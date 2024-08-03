/*
https://classroom.codingninjas.com/app/classroom/me/11692/content/204439/offering/2653310/problem/14247?leftPanelTabValue=PROBLEM
*/



// CONCEPT : to convert any binary tree into a BST, we can first get the inorder traversal of the current tree in an arr, and then compare
// it with a sorted arr of same elements. Because inorder traversal of a bst would always be a sorted array.
void collectNodesInInorder(vector<int> &arr, int i, vector<int> &inorder) {
    if(i >= arr.size()) return;

    collectNodesInInorder(arr, 2*i+1, inorder);
    inorder.push_back(arr[i]);
    collectNodesInInorder(arr, 2*i+2, inorder);
} 

int minimumSwaps(vector<int> &arr, int n) {
    // first collect the inorder traversal of current tree in an inorder arr
    vector<int> inorder;
    collectNodesInInorder(arr, 0, inorder);

    // now since we know that the inorder traversal of a bst would be simply a sorted arr,
    // so lets get the correct inorder of a bst by sorting the original arr
    sort(arr.begin(), arr.end());

    // now to get the minimum number of swaps needed to convert "inorder" into sorted "arr",
    // or in other words, convert any arr1 into any arr2, simply use the elem->index map technique always  
    unordered_map<int,int> elemPos; 
    // vector<int> elemPos(100005);  NOTE: instead of map, we can use simple arr also here, because arr[i] <= 100000, but CN platform was not accepting it

    for(int i=0; i<n; i++) elemPos[inorder[i]] = i;

    int swaps = 0;
    for(int i=0; i<n; i++){
        if(inorder[i] != arr[i]){
            swaps++;

            // first swap the elems in inorder arr
            int j = elemPos[arr[i]];
            inorder[i] ^= inorder[j] ^= inorder[i] ^= inorder[j];  // I am able to use this for swapping, because in question its given that elems are unique

            // now update positions of these elems in map
            elemPos[inorder[i]] = i;
            elemPos[inorder[j]] = j;
        }
    }

    return swaps;
}