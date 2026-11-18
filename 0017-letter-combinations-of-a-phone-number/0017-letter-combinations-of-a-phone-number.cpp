class Solution {
public:
    void getCombination(vector<string>& code, string digits, string& s, int i, vector<string>& comb){
        if(i == digits.size()){
            comb.push_back(s) ;
            return ;
        }

        int index = digits[i] - '0' ;
        string word = code[index] ;

        for(int j=0 ; j<word.size() ; j++){
            s.push_back(word[j]) ;
            getCombination(code, digits, s, i+1, comb) ;

            s.pop_back() ;
        }
    }

    vector<string> letterCombinations(string digits) {
        vector <string> code(27, "") ;

        int count = 0 ;
        for(int i=2 ; i<=9 ; i++){
            int lim = 3 ;
            if(i == 7 || i == 9) lim = 4 ;

            for(int j=0 ; j<lim ; j++){
                code[i] += ('a' + count) ;
                count++ ;
            }
        }

        vector <string> comb ;
        string s = "" ;

        getCombination(code, digits, s, 0, comb) ;

        return comb ;
    }
};