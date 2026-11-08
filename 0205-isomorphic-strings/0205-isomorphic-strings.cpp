class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false ;

        unordered_map <char, char> mp_1 ;
        unordered_map <char, char> mp_2 ;

        for(int i=0 ; i<s.size() ; i++){
            if(mp_1.find(s[i]) == mp_1.end() && mp_2.find(t[i]) == mp_2.end()){
                mp_1[s[i]] = t[i] ;
                mp_2[t[i]] = s[i] ;
            }else{
                if(mp_1[s[i]] != t[i] || mp_2[t[i]] != s[i]) return false ;
            }
        }
        return true ;
    }
};