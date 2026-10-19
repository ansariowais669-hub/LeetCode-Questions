class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size() ;

        int windowSize = 0 ;
        int maxWindowLength = 0 ;
        for(int i=0 ; i<n ; i++){
            if(nums[i] == 1 && i < n){
                while(i < n && nums[i] == 1){
                    i++ ;
                    windowSize++ ;
                }
                maxWindowLength = max(windowSize, maxWindowLength) ;
                windowSize = 0 ;
            }
        }
        return maxWindowLength ;
    }
};