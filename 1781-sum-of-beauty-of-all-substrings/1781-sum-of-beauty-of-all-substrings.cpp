class Solution {
public:
    int beautySum(string s) {
        int sum = 0 ;

        for(int i=0 ; i<s.size() ; i++){
            vector <int> freq(26,0) ;
            int most = 0 ;

            for(int j=i ; j<s.size() ; j++){
                freq[s[j]-'a']++ ;

                most = max(most, freq[s[j]-'a']) ;
                int least = s.size() ;

                for(int k=0 ; k<26 ; k++){
                    if(freq[k] > 0) least = min(least, freq[k]) ;
                }

                sum += (most - least) ;
            }
        }
        return sum ;
    }
};