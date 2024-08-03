/*
In an array of integers, find the consecutive subArray which has the max sum.
Print the maxSum and also print the subArray
*/

void kadane(int *a, int n)
{
    int maxSum = INT_MIN;
    int sum = 0;
    int ms, me, cs; // ms = maxSubArray start index, me = end index,
    // cs = current start, start index of current consecutive subArray

    for (int i = 0; i < n; i++)
    {
        if (sum == 0) // means now we have to start adding new subArray
        {
            cs = i;
        }

        sum += a[i]; // add current element to sum

        if (sum > maxSum) // then update the 3 things as below
        {
            maxSum = sum;
            ms = cs;
            me = i;
        }

        // if sum after adding the current element to current subArray becomes negatice then
        // don't continue the subArray forward
        if (sum < 0)
        {
            sum = 0;
        }
    }

    cout << "MAXSUM : " << maxSum << endl;

    for (int i = ms; i <= me; i++)
    {
        cout << a[i] << " ";
    }
}

// Another approach for kadane with using lesser variables
void kadane(vector<int> &a)
{
    int maxSum = INT_MIN;
    int sum = 0;
    int maxSumEnd = -1;

    int k = 0;
    while (k < a.size())
    {

        while (k < a.size() && sum >= 0)
        {
            sum += a[k++];
            if (sum > maxSum)
            {
                maxSum = sum;
                maxSumEnd = k - 1;
            }
        }

        sum = 0;
    }

    sum = a[maxSumEnd];
    k = maxSumEnd - 1;
    while (sum != maxSum)
    {
        sum += a[k--];
    }

    vector<int> ansSubArray;
    for (int j = k + 1; j <= maxSumEnd; j++)
    {
        ansSubArray.push_back(a[j]);
    }

    cout << endl;
    cout << "MAXSUM : " << maxSum << endl;
    cout << "MAX SUB ARRAY : ";
    for (int j = 0; j < ansSubArray.size(); j++)
    {
        cout << ansSubArray[j] << " ";
    }
}