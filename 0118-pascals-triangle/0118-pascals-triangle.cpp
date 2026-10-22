class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector <vector<int>> ans ;

        ans.push_back({1}) ;
        
        for(int i=1 ; i<numRows ; i++){
            int upper = i-1 ;
            vector <int> row ;
            row.push_back(1) ;

            for(int j=1 ; j<i ; j++){
                row.push_back(ans[upper][j-1] + ans[upper][j]) ;
            }

            row.push_back(1) ;

            ans.push_back(row) ;
        }
        return ans ;
    }
};