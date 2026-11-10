class Solution {
public:
    int myAtoi(string s) {
        bool negative = false ;
        bool encounter = false ;
        long long num = 0 ;

        for(int i = 0 ; i<s.size() ; i++){
            char ch = s[i] ;
            if(ch == ' ' && !encounter) continue ;

            int dig = ch - '0' ;
            if(!encounter && ((ch == '-') || (ch == '+'))){
                if(s[i] == '-') negative = true ;
                else negative = false ;
                encounter = true ;
                continue ;
            }

            if(dig < 0 || dig > 9) break ;
            encounter = true ;

            long long limit = negative ? 2147483648LL : 2147483647LL;

            if(num > limit / 10 ||
               (num == limit / 10 && dig > limit % 10)) {
                return negative ? INT_MIN : INT_MAX;
            }

            num = num*10 + dig ;
        }

        if(negative) return -num ;
        return num ;
    }
};