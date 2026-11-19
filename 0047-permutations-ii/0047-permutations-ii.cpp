class Solution {
public:
    set <vector<int>> s ;

    void getPermutations(vector<int>& nums, int idx, vector<vector<int>>& comb){
        if(idx == nums.size()){
            if(s.find(nums) == s.end()){
                comb.push_back({nums}) ;
                s.insert(nums) ;
            }
            return ;
        }

        for(int i=idx ; i<nums.size() ; i++){
            swap(nums[i], nums[idx]) ;

            getPermutations(nums, idx+1, comb) ;

            swap(nums[i], nums[idx]) ;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector <vector<int>> comb ;

        getPermutations(nums, 0, comb) ;

        return comb ;
    }
};