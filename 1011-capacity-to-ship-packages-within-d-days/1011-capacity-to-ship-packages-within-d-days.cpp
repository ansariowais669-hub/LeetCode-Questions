class Solution {
public:
    int isValid(vector <int>& weights, int capacity){
        int day_count = 1 ;
        int curr_weight = 0 ;

        for(int i=0 ; i<weights.size() ; i++){
            if(weights[i] + curr_weight <= capacity) curr_weight += weights[i] ;
            else{
                day_count++ ;
                curr_weight = weights[i] ;
            }     
        }
        return day_count ;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int st = 0 ; int end = 0 ;
        for(int i=0 ; i<weights.size() ; i++){
            end += weights[i] ;
            st = max(st, weights[i]) ;
        }

        int ans = end ;
        while(st <= end){
            int mid = st + (end-st)/2 ;

            if(isValid(weights, mid) <= days){ // as if the capacity gives us less days that is also acceptable we can change the load each day accordingly
                ans = mid ;
                end = mid - 1 ;
            }else st = mid + 1 ; 
        }

        return ans ;
    }
};