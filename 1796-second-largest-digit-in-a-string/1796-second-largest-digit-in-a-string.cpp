class Solution {
public:
    int secondHighest(string s) {
        int high1 = INT_MIN ;
        int high2 = INT_MIN ;
        for(int i=0 ; i<s.size() ; i++){
            int dig = s[i] - '0' ;
            if(dig >= 0 && dig <=9){
                if(dig == high1) continue ;
                if(dig > high1){
                 high2 = high1 ;
                 high1 = dig ;
                }
                else if(dig > high2) high2 = dig ;
            }
        }
        if(high1 == high2) return -1 ;
        if(high2 == INT_MIN) return -1 ;
        return high2 ;
    }
};