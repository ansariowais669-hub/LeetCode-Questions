class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false ;

        goal += goal ;
        int i = goal.find(s) ;
        
        if(i >= 0 && i <= s.length()) return true ;
        return false ;
    }
};