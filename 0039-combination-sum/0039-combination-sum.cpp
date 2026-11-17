class Solution {
public:
    set <vector<int>> s ;

    void sequences(vector<int>& candidates, int target, int i, vector<int>& ans,vector<vector<int>>& subsequences){
        if(i >= candidates.size() || target < 0) return ;

        if(target == 0){
            if(s.find(ans) == s.end()){
                subsequences.push_back({ans}) ;
                s.insert(ans) ;
            }
            return ;
        }

        //include and move
        ans.push_back(candidates[i]) ;
        sequences(candidates, target-candidates[i], i+1, ans, subsequences) ;

        // include and stay
        sequences(candidates, target-candidates[i], i, ans, subsequences) ;

        //exclude
        ans.pop_back() ;
        sequences(candidates, target, i+1, ans, subsequences) ;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> unique ;
        vector <int> ans ;

        sequences(candidates, target, 0, ans, unique) ;

        return unique ;
    }   
};