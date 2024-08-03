int partition(int *a, int si, int ei){
    int count=0,temp;
    for(int i=si+1; i<=ei; i++){
        if(a[i]<=a[si]){
            count++;
        }
    }
    temp=a[si];
    a[si]=a[si+count];
    a[si+count]=temp;
    
    int i=si,j=ei;
    while(i<si+count && j>si+count){ //because if pivot is at the correct position, then all nums bigger than pivot should be accomodated on the right, and all lesser nums than pivot should be accomodated to the left
        if(a[i]<=a[si+count]){
            i++;
        }
        else if(a[j]>a[si+count]){
            j--;
        }
        else{
            //if the above 2 conditions fail then we reach here in which
            //we basically say that as both the conditions are false so 
            //swap the two elements 
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i++;j--;
        }
    }
    
    return si+count;
}

void helper(int *input, int si, int ei){
    //I wanted my quicksort function to have si and ei arguments instead of size
    //so i created a helper function which now serves as my main quicksort function
    //so i immediately call helper function from quicksort function given in the question
    if(si>=ei){
        return;
    }
    
    int c=partition(input, si, ei);
    helper(input, si, c-1);
    helper(input, c+1, ei);
}

void quickSort(int input[], int size) {
	helper(input, 0, size-1);
}