class Solution {
public:
    string frequencySort(string s) {
        unordered_map <char, int> hashmap ;

        for(char ch : s) hashmap[ch]++ ;

        vector <vector<char>> bucket(s.size()+1) ;

        for(auto val : hashmap) bucket[val.second].push_back(val.first) ;

        string ans = "" ;
        for(int i=s.size() ; i>=1 ; i--){
            for(char ch : bucket[i]) ans += string(i, ch) ;
        }

        return ans ;
    }
};