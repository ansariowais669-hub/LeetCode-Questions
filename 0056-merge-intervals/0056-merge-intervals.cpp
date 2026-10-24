class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size() ;

        int counter = -1 ;
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {return a[0] < b[0] ;}) ;
        vector <vector <int>> ans ;

        if(n == 1){
            ans.push_back(intervals[0]) ;
            return ans ;
        }

        for(int p=0 ; p<n-1 ; p++){
            if(counter >= 0 && intervals[p][0] <= ans[counter][1]){
                if(ans[counter][1] >= intervals[p][1]) continue ;
                else {
                    ans[counter][1] = intervals[p][1] ;
                }
            }else if(p <= n-2 && intervals[p][1] >= intervals[p+1][0]){
                int i = intervals[p][0] ;
                int k = intervals[p+1][0] ;
                int j = intervals[p][1] ;
                int l = intervals[p+1][1] ;

                vector <int> seq ;
                if(j <= l){
                    seq.push_back(i) ;
                    seq.push_back(l) ;
                } else {
                    seq.push_back(i) ;
                    seq.push_back(j) ;
                }

                p++ ;
                ans.push_back(seq) ;
                counter++ ;
            }else{
                ans.push_back(intervals[p]) ;
                counter++ ;
            }
        }
        
        if (ans[counter][1] < intervals[n-1][0]){
            ans.push_back(intervals[n-1]) ;
        }else{
            if(ans[counter][1] <= intervals[n-1][1]){
                ans[counter][1] = intervals[n-1][1] ;  
            }
        }

        return ans ;
    }
};