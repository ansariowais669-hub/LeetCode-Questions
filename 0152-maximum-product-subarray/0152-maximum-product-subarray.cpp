class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxEnding = nums[0] ;
        int minEnding = nums[0] ;
        int ans = nums[0] ;

        for(int i=1 ; i<nums.size() ; i++){
            int x = nums[i] ;

            if(x < 0) swap(maxEnding, minEnding) ;

            maxEnding = max(x , maxEnding * x) ;
            minEnding = min(x , minEnding * x) ;
            ans = max(ans , maxEnding) ;
        }
        return ans ;
    }
};