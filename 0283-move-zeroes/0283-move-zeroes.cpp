class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i] == 0){
                int ran = i ;
                while(nums[ran] == 0){
                    if(ran == nums.size()-1) return ;
                    ran++ ;
                }
                swap(nums[i],nums[ran]) ;
            }
        }
    }
};