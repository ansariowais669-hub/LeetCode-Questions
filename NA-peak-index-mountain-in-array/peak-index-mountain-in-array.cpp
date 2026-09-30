#include <iostream>
#include <vector>

using namespace std;

int PeakIndex (vector <int>& nums , int target){
    int s=1 , e = nums.size()-2;

    while (s <= e){
        int mid = s + (e-s)/2 ;
        if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]) return mid;
        
        if(nums[mid-1] < nums[mid]) s = mid+1 ;
        else e = mid-1 ;
    }
    return -1 ;
}
