class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int low = 0 ;
        int k = 0 ;

        for(int i=0 ; i<nums.size() ; i++){
            while((i+1<nums.size()) && nums[i+1] == nums[i]) i++ ;
            swap(nums[i], nums[low]) ;
            k++ ; low++ ;
        }
        return k ;
    }
};

// if(nums[i] != nums[i-1]){
//                 k++ ;
//                 swap(nums[i], nums[low]) ;
//                 low++ ;
//                 }
//             else{
//                 while(nums[i-1] == nums[i]) i++ ;
//                 swap(nums[low], nums[i]) ;
//                 low++ ; k++ ; i++ ;
//             }