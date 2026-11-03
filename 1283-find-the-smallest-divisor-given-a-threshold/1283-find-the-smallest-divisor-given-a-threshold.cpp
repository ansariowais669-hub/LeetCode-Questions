class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int st = 1 ; int end = *max_element(nums.begin(), nums.end()) ;
        int ans = 0 ;

        while(st <= end){
            int mid = st + (end-st)/2 ;
            int sum = 0 ;
            for(int i=0 ; i<nums.size() ; i++) sum += ((nums[i] + mid - 1)/mid) ;

            if(sum > threshold) st = mid + 1 ;
            else {
                ans = mid ;
                end = mid - 1 ;
            }
        }

        return ans ;
    }
};