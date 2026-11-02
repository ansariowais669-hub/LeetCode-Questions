class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size()-1 ;

        int st = 0 ; int end = n ;
        while(st <= end){
            int mid = st + (end-st)/2 ;

            if(nums[mid] == target) return true ;

            if(nums[st] == nums[mid] && nums[end] == nums[mid]){
                st++ ; end-- ;
            }
            else if(nums[st] <= nums[mid]){ // left-sorted
                if(nums[mid] > target && nums[st] <= target) end = mid-1 ;
                else st = mid+1 ;
            } else{ // right-sorted
                if(nums[mid] < target && nums[end] >= target) st = mid+1 ;
                else end = mid - 1 ;
            }
        }
        return false ;
    }
};