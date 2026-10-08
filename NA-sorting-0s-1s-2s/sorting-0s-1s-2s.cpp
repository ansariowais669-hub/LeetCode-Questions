#include <bits/stdc++.h>
using namespace std;

void sortColors(vector <int>& nums){
    int count_0 = 0 , count_1 = 0 , count_2 = 0 ;
    for(int i=0 ; i<nums.size() ; i++){
        if( nums[i] == 0) count_0++;
        else if (nums[i] == 1) count_1++ ;
        else count_2++;
    }
    for(int i=0 ; i<nums.size() ; i++){
        if(count_0 > 0){
            nums[i] = 0 ;
            count_0--;
        }else if(count_1 > 0){
            nums[i] = 1;
            count_1-- ;
        }else if(count_2 > 0){
            nums[i] = 2;
            count_2--;
        }
    }
}

//DNF Sorting Algorithm - O(n)
void DNF(vector <int>& nums){
    int low = 0, mid = 0 , high = nums.size()-1 ;
    while (mid <= high){
        if(nums[mid] == 0){
            swap(nums[low], nums[mid]) ;
            low++;
            mid++;
        }else if (nums[mid] == 1){
            mid++;
        }else{
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main(){
    vector <int> nums = {2,0,2,1,1,0,1,2,0,0} ;
    // sortColors(nums) ;
    DNF(nums);
    for(int i=0 ; i<nums.size() ; i++) cout << nums[i] << " " ;
    cout << endl ;
}
