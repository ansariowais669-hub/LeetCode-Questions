class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector <pair<int,int>> coordinates ;
        int m = matrix.size() ;
        int n = matrix[0].size() ;

        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(matrix[i][j] == 0) coordinates.push_back({i,j}) ;
            }
        }

        for(auto val : coordinates){
            int i = val.first ;
            int j = val.second ;

            for(int u=0 ; u<m ; u++) matrix[u][j] = 0 ;
            for(int v=0 ; v<n ; v++) matrix[i][v] = 0 ;
        }
    }
};