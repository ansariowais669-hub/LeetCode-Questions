class Solution {
public:
    bool isPalindrome(string s , int st , int end){
        while(st < end){
            if(s[st] != s[end]) return false ;
            st++ ; end-- ;
        }
        return true ;
    }

    string longestPalindrome(string s) {
        if(s.size() == 1) return s ;
        string palindrome = "" ;

        for(int i = 0 ; i<s.size() ; i++){
            for(int j=s.size()-1 ; j>i ; j--){
                if(s[i] == s[j]){
                    if(j-i+1 <= palindrome.size()) continue ;

                    if(isPalindrome(s, i, j)) palindrome = s.substr(i, j-i+1) ;
                }
            }
        }
        if(palindrome == "") palindrome += s[0] ;
        return palindrome ;
    }
};