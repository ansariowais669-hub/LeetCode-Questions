class Solution {
public:
    int lcs(string s , string t){
        int n = s.size() ;
        int m = t.size() ;

        vector<int> prev(n+1, 0), curr(n+1, 0) ;

        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=m ; j++){
                if(s[i-1] == t[j-1]) curr[j] = 1 + prev[j-1] ;
                else curr[j] = max(prev[j], curr[j-1]) ;
            }

            prev = curr ;
            fill(curr.begin(), curr.end(), 0) ;
        }
        return prev[n] ;
    }

    int minInsertions(string s) {
        string t = s ;
        reverse(s.begin(), s.end()) ;
        int longest_sequence = lcs(s ,t) ;

        return (s.size() - longest_sequence) ;
    }
};