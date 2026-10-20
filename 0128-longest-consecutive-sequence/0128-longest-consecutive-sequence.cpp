class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> s ;
        for(int i=0 ; i<nums.size() ; i++) s.insert(nums[i]) ;

        int maxCount = 0 ;
        unordered_set <int> included ;

        for(int val : s){
            if(included.find(val) == included.end()){
                included.insert(val) ;
                int i = 1 ;
                int leftCount = 0 ;
                int rightCount = 0 ;
                while(s.find(val-i) != s.end()){
                    if(included.find(val-i) == included.end()){
                    leftCount++ ;
                    included.insert(val-i) ;
                    } else{
                        break ;
                    }
                    i++ ;
                }
                i = 1 ;
                while(s.find(val+i) != s.end()){
                    if(included.find(val+i) == included.end()){
                    rightCount++ ;
                    included.insert(val+i) ;
                    } else{
                        break ;
                    }
                    i++ ;
                }
                maxCount = max(leftCount+rightCount+1, maxCount) ;
            }
        }   
        return maxCount ;
    }
};