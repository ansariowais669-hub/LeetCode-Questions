class Solution {
public:
    void DFS(int i, int j ,vector<vector<int>>& image,vector<vector<bool>>& vis,int orgColor,int color){
        if(i>=image.size() || j>=image[0].size() || i<0 || j<0 || image[i][j] != orgColor || vis[i][j] == true) return ;
        
        vis[i][j] = true ;

        image[i][j] = color ;

        DFS(i-1,j,image,vis,orgColor,color) ;
        DFS(i+1,j,image,vis,orgColor,color) ;
        DFS(i,j-1,image,vis,orgColor,color) ;
        DFS(i,j+1,image,vis,orgColor,color) ;

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int orgColor = image[sr][sc] ;
        vector<vector<bool>> vis(image.size(),vector<bool>(image[0].size(),false)) ; 

        DFS(sr,sc,image,vis,orgColor,color) ;

        return image ;
    }
};