class Solution {
public:
    void getSequence(vector<int>& candidates, int target, int i, vector<int>& ans, vector<vector<int>>& sequence){
        if(target == 0){
            sequence.push_back({ans}) ;
            return ;
        }

        if(i >= candidates.size() || target < 0) return ;

        // include
        ans.push_back(candidates[i]) ;
        getSequence(candidates, target-candidates[i], i+1, ans, sequence) ;

        // exclude
        ans.pop_back() ;
        int next = i + 1 ;

        while(next < candidates.size() && candidates[next] == candidates[i]) next++ ; // to avoid duplicate sequence (we get the double 1's but after inclusion call of 1 and then into next 1 by second recursion call ; exclude in the same recursion call avoids this same sequence by doing this while loop)

        getSequence(candidates, target, next, ans, sequence) ;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> sequence ;
        vector <int> ans ;

        sort(candidates.begin(), candidates.end()) ;

        getSequence(candidates, target, 0, ans, sequence) ;
        
        return sequence ;
    }
};