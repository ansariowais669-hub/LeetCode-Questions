class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack <pair<int, bool>> s ;

        if(asteroids[0] >= 0) s.push({asteroids[0], true}) ;
        else s.push({-asteroids[0], false}) ;

        for(int i=1 ; i<asteroids.size() ; i++){
            int asteroid = abs(asteroids[i]) ;
            bool positive = asteroids[i] > 0 ? true : false ;

            bool flag = false ;

            while(s.size() && s.top().second && !positive){
                if(flag) break ;

                if(asteroid == s.top().first){
                    s.pop() ;
                    flag = true ;

                    continue ;
                }else if(asteroid > s.top().first) s.pop() ;
                else{
                    flag = true ;
                    break ;
                }
            }
            if(!flag) s.push({asteroid, positive}) ;
        }

        if(s.size() == 0) return {} ;
        else if(s.size() == 1){
            if(s.top().second) return {s.top().first} ;
            else return {-s.top().first} ;
        }

        vector <int> ans ;
        while(s.size()){
            auto val = s.top() ;
            s.pop() ;

            if(val.second) ans.push_back(val.first) ;
            else ans.push_back(-val.first) ;
        }

        reverse(ans.begin(), ans.end()) ;
        return ans ;
    }
};