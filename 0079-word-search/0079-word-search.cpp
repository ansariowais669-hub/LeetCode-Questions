class Solution {
public:
    bool check(vector<vector<char>>& board, string word, int idx, int i, int j){
        if(idx == word.size()) return true ;

        if(i >= board.size() || j >= board[0].size() || i < 0 || j < 0) return false ;

        if(word[idx] == board[i][j]){
            char c = board[i][j] ;
            board[i][j] = '-' ;

            bool check1 = check(board, word, idx+1, i+1, j) ;
            bool check2 = check(board, word, idx+1, i-1, j) ;
            bool check3 = check(board, word, idx+1, i, j+1) ;
            bool check4 = check(board, word, idx+1, i, j-1) ;

            board[i][j] = c ;

            return check1 || check2 || check3 || check4 ;
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