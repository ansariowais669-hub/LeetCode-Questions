class Solution {
public:
    int romanToInt(string s) {
        int ans = 0 ;

        for(int i=0 ; i<s.size() ; i++){
            char ch = s[i] ;

            if(ch == 'M') ans += 1000 ;
            else if(ch == 'D') ans += 500 ;
            else if(ch == 'C'){
                if(s[i+1] == 'D'){
                    ans += 400 ; i++ ;
                }else if(s[i+1] == 'M'){
                    ans += 900 ; i++ ;
                }
                else ans += 100 ;
            }
            else if(ch == 'L') ans += 50 ;
            else if(ch == 'X'){
                if(s[i+1] == 'L'){
                    ans += 40 ; i++ ;
                }else if(s[i+1] == 'C'){
                    ans += 90 ; i++ ;
                }
                else ans += 10 ;
            }
            else if(ch == 'V') ans += 5 ;
            else { // ch == 'I
                if(s[i+1] == 'V'){
                    ans += 4 ; i++ ;
                }else if(s[i+1] == 'X'){
                    ans += 9 ; i++ ;
                }
                else ans += 1 ;
            }
        }
        return ans ;
    }
};