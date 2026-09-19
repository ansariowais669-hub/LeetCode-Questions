#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector <int> &nums){
    int currSum = 0 , maxSum = 0;
    for(auto val:nums){
        currSum += val ;
        maxSum = max(currSum,maxSum);
        if(currSum<0) currSum = 0;
    }
    return maxSum ;
}
