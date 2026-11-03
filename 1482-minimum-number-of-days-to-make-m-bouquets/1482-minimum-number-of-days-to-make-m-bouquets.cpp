class Solution {
public:
    bool isValid(vector <int>& nums, int st , int mid , int end, int m , int k){
        int flowers = k ;
        int bouquets = m ; 

        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i] <= mid){
                flowers-- ;
                if(flowers == 0){
                    bouquets-- ;
                    flowers = k ;
                    if(bouquets == 0) return true ;
                }
            }else flowers = k ;
        }
        if(bouquets == 0) return true ;
        return false ;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int maximum = INT_MIN ;
        int minimum = INT_MAX ;
        for(int i=0 ; i<bloomDay.size() ; i++){
            maximum = max(maximum, bloomDay[i]) ;
            minimum = min(minimum, bloomDay[i]) ;
        }

        int st = minimum ;
        int end = maximum ;
        int ans = -1 ;

        while(st <= end){
            int mid = st + (end-st)/2 ;

            if(isValid(bloomDay, st, mid, end, m, k)){
                ans = mid ;
                end = mid - 1 ;
            }else st = mid + 1 ;
        }

        return ans ;
    }
};