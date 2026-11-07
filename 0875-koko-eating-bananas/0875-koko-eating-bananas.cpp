class Solution {
public:
    long long timeTaken(vector<int>& piles, int capacity){
        long long time = 0 ;

        for(int i=0 ; i<piles.size() ; i++){
            time += (piles[i] + (long long)capacity - 1) / capacity ;
        }

        return time ;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        if(h < piles.size()) return -1 ;

        int st = 1 ;
        int end = *max_element(piles.begin(), piles.end()) ;

        int ans = -1 ;

        while(st <= end){
            int mid = st + (end-st)/2 ;

            long long time_mid = timeTaken(piles, mid) ;
            if(time_mid <= h){
                end = mid - 1 ;
                ans = mid ;
            }
            else st = mid + 1 ;
        }

        return ans ;
    }
};