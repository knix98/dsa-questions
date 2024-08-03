/*
Problem : Ninja's task  on Codestudio

basically the problem stated that , as the range of numbers given as input is small, you have to sort this array in O(n)
*/



// So apply count sort algo
#include <bits/stdc++.h> 
vector<int> sort(vector<int> &nums, int n)
{
    int minValue = nums[0];
    int maxValue = nums[0];

    for(int i=0; i<n; i++){
        minValue = minValue < nums[i] ? minValue : nums[i];        
        maxValue = maxValue > nums[i] ? maxValue : nums[i];
    }

    int rangeMax = maxValue - minValue;

    int freq[rangeMax+1] = {0};

    for(int i=0; i<n; i++){
        freq[nums[i] - minValue]++;
    }

    int j=0;
    for(int i=0; i<rangeMax+1; i++){
        if(freq[i]){
            while(freq[i]--) nums[j++] = (i + minValue);
        }
    }

    return nums;
}