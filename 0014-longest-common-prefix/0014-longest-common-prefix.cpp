class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1) return strs[0] ;

        int i = 0 ;
        string ans = "" ;

        while(true){
            string sub = strs[0].substr(0, i+1) ;

            for(int j=1 ; j<strs.size() ; j++){
                if(strs[j].size() < i+1) return ans ;

                if(strs[j].substr(0, i+1) != sub) return ans ;
            }

            ans = sub ;
            i++ ;
        }

        return "" ;
    }
};