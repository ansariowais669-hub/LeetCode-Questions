class Solution {
public:

    bool check(vector<vector<char>>& board, string word, int idx, int i, int j){
        if(idx == word.size()) return true ;

        if(i >= board.size() || j >= board[0].size() || i < 0 || j < 0) return false ;

        if(word[idx] == board[i][j]){
            char c = board[i][j] ;
            board[i][j] = '-' ; // so that when we go back to previous cell from which we recursed by check1234 functions then we can return false from that as we do not want to go there

            bool found = check(board, word, idx+1, i+1, j) || check(board, word, idx+1, i-1, j) || check(board, word, idx+1, i, j+1) || check(board, word, idx+1, i, j-1) ;

            board[i][j] = c ; // backtrack

            return found ;
        }
        return false ;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size() ; int n = board[0].size() ;

        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(check(board, word, 0, i, j)) return true ;
            }
        }

        return false ;
    }
};