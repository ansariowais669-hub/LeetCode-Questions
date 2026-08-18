class Solution {
public:
    void dfs(int i , vector<vector<int>>& isConnected , vector <bool>& vis){
        vis[i] = true ;

        for(int j=0 ; j<isConnected[i].size() ; j++){
            if(isConnected[i][j] == 1 && !vis[j]) dfs(j,isConnected,vis) ;
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        vector <bool> vis (isConnected[0].size(),false) ;
        int count = 0 ;

        for(int i=0 ; i<isConnected[0].size() ; i++){
            if(!vis[i]){
                dfs(i,isConnected,vis) ;
                count++ ;
            }
        }
        return count ;
    }
};