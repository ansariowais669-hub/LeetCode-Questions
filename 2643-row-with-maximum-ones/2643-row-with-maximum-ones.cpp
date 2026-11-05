class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size() ; int n = mat[0].size() ;

        vector <int> ans = {0,0} ;

        for(int i = 0 ; i<m ; i++){
            int sum = 0 ;
            for(int j = 0 ; j < n ; j++){
                sum += mat[i][j] ;
            }
            if(sum > ans[1]){
                ans[0] = i ;
                ans[1] = sum ;
            }
        }

        return ans ;
    }
};