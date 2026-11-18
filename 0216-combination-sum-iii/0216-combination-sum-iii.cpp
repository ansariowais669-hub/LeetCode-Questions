class Solution {
public:
    void getSum(vector<int>& nums, int target, int i, int k, vector<int>& ans, vector <vector<int>>& comb){
        if(target == 0 && k == 0){
            comb.push_back({ans}) ;
            return ;
        }

        if(i == nums.size() || target < 0 || k < 0) return ;

        // Pruning conditions
        if(nums.size() - i < k) return ; // if we have less than k elements then break
        if(nums[i] > target) return ; // if current element is greater than target then no solution exits from current i to last index

        //include
        ans.push_back(nums[i]) ;
        getSum(nums, target-nums[i], i+1, k-1, ans, comb) ;

        // exclude
        ans.pop_back() ;
        getSum(nums, target, i+1, k, ans, comb) ;
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector <int> ans ;
        vector <vector<int>> comb ;

        vector <int> nums ;
        for(int i=1 ; i<=9 ; i++) nums.push_back(i) ;

        getSum(nums, n, 0, k, ans, comb) ;

        return comb ;
    }
};