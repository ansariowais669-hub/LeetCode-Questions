class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size() ;
        stack <int> s ;

        vector <int> PGE(n) , NGE(n) ; 
        vector <int> PSE(n) , NSE(n) ;

        // Getting Next Greater Element
        for(int i=n-1 ; i>=0 ; i--){
            while(s.size() && nums[s.top()] < nums[i]) s.pop() ;

            NGE[i] = s.empty() ? n : s.top() ;
            s.push(i) ;
        }

        while(!s.empty()) s.pop() ;

        // Getting Previous Greater Element
        for(int i=0 ; i<n ; i++){
            while(s.size() && nums[s.top()] <= nums[i]) s.pop() ;

            PGE[i] = s.empty() ? -1 : s.top() ;
            s.push(i) ; 
        }

        while(!s.empty()) s.pop() ;

        // Getting Next Smaller or equal Element
        for(int i=n-1 ; i>=0 ; i--){
            while(s.size() && nums[s.top()] > nums[i]) s.pop() ;

            NSE[i] = s.empty() ? n : s.top() ;
            s.push(i) ;
        }

        while(!s.empty()) s.pop() ;

        // Getting Previous Smaller Element
        for(int i=0 ; i<n ; i++){
            while(s.size() && nums[s.top()] >= nums[i]) s.pop() ;

            PSE[i] = s.empty() ? -1 : s.top() ;
            s.push(i) ; 
        }

        while(!s.empty()) s.pop() ;

        long long maxSum = 0 ;
        long long minSum = 0 ;

        long long totalSum = 0 ;

        for(int i=0 ; i<n ; i++){
            maxSum = 1LL * (i-PGE[i]) * (NGE[i]-i) * nums[i] ;
            minSum = 1LL * (i-PSE[i]) * (NSE[i]-i) * nums[i] ;

            totalSum += (maxSum - minSum) ;
        }

        return totalSum ;
    }
};