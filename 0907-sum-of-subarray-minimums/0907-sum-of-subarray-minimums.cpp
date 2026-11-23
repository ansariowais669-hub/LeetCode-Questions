class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9 + 7 ;

        vector <int> left(arr.size()), right(arr.size()) ;
        stack <int> s ;

        // elements on left side such that arr[i] is smallest
        for(int i=0 ; i<arr.size() ; i++){
            while(s.size() && arr[s.top()] > arr[i]) s.pop() ;

            left[i] = s.empty() ? i+1 : i-s.top() ; // no of elements on left greater than arr[i]
            s.push(i) ;
        }

        while(!s.empty()) s.pop() ;

        // elements on right side such that arr[i] is smallest
        for(int i=arr.size()-1 ; i>=0 ; i--){
            while(s.size() && arr[s.top()] >= arr[i]) s.pop() ;

            right[i] = s.empty() ? arr.size()-i : s.top()-i ;
            s.push(i) ;
        }

        long long sum = 0 ;
        for(int i=0 ; i<arr.size() ; i++){
            long long contri = (1LL * arr[i] * left[i] * right[i]) % mod ; // no of subarrays with arr[i] as min left[i] * right[i]

            sum = (sum + contri) % mod ;
        }

        return sum ;
    }
};