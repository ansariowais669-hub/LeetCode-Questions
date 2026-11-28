class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sumOfRanges = 0 ;
        long long lastSum = 0 ;

        for(int i=0 ; i<nums.size() ; i++){
            int mini = nums[i] ;
            int maxi = nums[i] ;

            for(int j=i+1 ; j<nums.size() ; j++){
                maxi = max(nums[j], maxi) ;
                mini = min(nums[j], mini) ;
                
                sumOfRanges += 1LL * (maxi - mini) ;
            }
        }

        return sumOfRanges ;
    }
};