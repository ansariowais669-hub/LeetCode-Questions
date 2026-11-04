class Solution {
public:
    bool isValid(vector<int>& nums, int k ,int maxSum){
        int subArray = 1 ;
        int currSum = 0 ;
        for(int i=0 ; i<nums.size() ; i++){
            if(currSum + nums[i] <= maxSum) currSum += nums[i] ;
            else{
                currSum = nums[i] ;
                subArray++ ;
            }
        }
        return subArray <= k ? true : false ;
    }

    int splitArray(vector<int>& nums, int k) {
        int st = 0 ; int end = 0 ;
        for(int i=0 ; i<nums.size() ; i++){
            st = max(st ,nums[i]) ;
            end += nums[i] ;
        }

        int ans = end ;
        while(st <= end){
            int mid = st + (end-st)/2 ;

            if(isValid(nums, k, mid)){
                ans = mid ;
                end = mid - 1 ;
            }else st = mid + 1 ;
        }

        return ans ;
    }
};