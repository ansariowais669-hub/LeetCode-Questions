class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()) ;
        int n = nums.size() ;
        int closestSum = nums[0] + nums[1] + nums[2] ;
        int minDiff = abs(target - (nums[0]+nums[1]+nums[2])) ;
        
        for(int i=0 ; i<n ; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue ;

            int j = i+1 ; int k = n - 1 ;

            while(j < k){
                int currSum = nums[i] + nums[j] + nums[k] ;
                int currDiff = abs(currSum - target) ;

                if(currDiff < minDiff){
                    closestSum = currSum ;
                    minDiff = currDiff ;
                }

                if(currSum == target) return target ;
                else if(target > currSum) j++ ;
                else k-- ;
            }
        }

        return closestSum ;
    }
};