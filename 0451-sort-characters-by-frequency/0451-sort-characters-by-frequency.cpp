class Solution {
public:
    string frequencySort(string s) {
        unordered_map <char, int> hashmap ;

        for(int i=0 ; i<s.size() ; i++){
            if(hashmap.find(s[i]) == hashmap.end()) hashmap[s[i]] = 1;
            else hashmap[s[i]]++ ;
        }

        priority_queue <pair<int, char>> pq ;
        for(auto val : hashmap) pq.push({val.second, val.first}) ;

        string ans = "" ;
        while(pq.size()){
            auto val = pq.top() ;
            pq.pop() ;

            int freq = val.first ;
            char ch = val.second ;

            while(freq--) ans += ch ;
        }
        return ans ;
    }
};