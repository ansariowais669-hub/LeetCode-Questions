class Solution {
public:
    int beautySum(string s) {
        int sum = 0 ;

        for(int i=0 ; i<s.size() ; i++){
            vector <int> freq(26,0) ;
            for(int j=i ; j<s.size() ; j++){
                freq[s[j]-'a']++ ;

                int most = 0 ; int least = s.size() ;

                for(int k=0 ; k<26 ; k++){
                    most = max(most, freq[k]) ;
                    if(freq[k] > 0) least = min(least, freq[k]) ;
                }

                sum += (most - least) ;
            }
        }
        return sum ;
    }
};