class Solution {
public:
    void getPermutations(vector<int>& nums, int idx, vector<vector<int>>& comb){
        if(idx == nums.size()){
            comb.push_back({nums}) ;
            return ;
        }

        unordered_set <int> s ;

        for(int i=idx ; i<nums.size() ; i++){
            if(s.find(nums[i]) != s.end()) continue ;

            s.insert(nums[i]) ;
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