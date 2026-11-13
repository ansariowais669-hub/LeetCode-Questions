class Solution {
public:
    int getNext(vector<int>& nums, int i){
        int n = nums.size() ;

        return (((i + nums[i]) % n) + n) % n ; // to not return negative index
    }

    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size() ;

        for(int i=0 ; i<n ; i++){
            int slow = i ;
            int fast = i ;

            bool direction = nums[i] > 0 ;

            while(true){
                int nextSlow = getNext(nums, slow) ;
                if((nums[nextSlow]>0) != direction) break ;

                int nextFast = getNext(nums, fast) ;
                if((nums[nextFast]>0) != direction) break ;

                nextFast = getNext(nums, nextFast) ;
                if((nums[nextFast]>0) != direction) break ;

                fast = nextFast ;
                slow = nextSlow ;

                if(slow == fast){
                    if(slow == getNext(nums, slow)) break ;

                    return true ;
                }
            }
        }
        return false ;
    }
};