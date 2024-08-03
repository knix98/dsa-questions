void mergeSort(int input[], int si, int ei){
    if(si >= ei){ //base case
        return;
    }
    
    int mid = (si + ei)/2; //split into 2 parts and sort both the parts
    mergeSort(input, si, mid);
    mergeSort(input, mid+1, ei);
    
    int size = ei - si + 1;
    int sorted[size]; //this will store the elements of the both the sorted parts in sorted order
    
    int i=si, j=mid+1, k=0; //i will travel over 1st sorted part, j over 2nd part, k over the final sorted array
    for( ; i<=mid && j<=ei; ){
        if(input[i] <= input[j]){
            sorted[k] = input[i];
            i++;
        }
        else{
            sorted[k] = input[j];
            j++;
        }
        
        k++;
    }
    
    if(i<=mid){
        while(k<size){
            sorted[k] = input[i];
            i++;k++;
        }
    }
    else if(j <= ei){
        while(k<size){
            sorted[k] = input[j];
            j++;k++;
        }
    }
    
    for(int x=si,y=0; x<=ei; x++,y++){ //copy the sorted array into the given input array
        input[x] = sorted[y]; //the indexes of both the arrays are different
    }
}

void mergeSort(int input[], int size){
    mergeSort(input, 0, size-1);
}