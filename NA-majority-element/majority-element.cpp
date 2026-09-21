#include <bits/stdc++.h>
using namespace std;

int majorityElement (vector <int> &nums){
    int n = nums.size();
    sort(nums.begin(),nums.end());
    int freq = 1 , ans = nums[0];
    for(int i=1 ; i<n ; i++){
        if(nums[i] == nums[i-1]){
            freq++;
            if(freq>n/2) return ans;
        }else{
            freq = 1;
            ans = nums[i];
        }
    }
    return ans;
} // O(nlogn)


//Moore's voting Algoithm -- it says that always add frequency for similar element and subtract it for different elements, at the end we will get the element of majority as subtracting from frequency of majority element would never be less than 0 as it's frequency is more than n/2 floor.

#include <bits/stdc++.h>
using namespace std;

int majorityElement (vector <int> &nums){
    int freq = 0, ans = 0;
    for(int i=1 ; i<nums.size() ; i++){
        if(freq == 0) ans = nums[i];
        if(ans == nums[i]) freq++ ;
        else freq-- ;
    }
    return ans;
}

