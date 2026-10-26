class Solution {
public:

    int merge(vector <int>& nums, int st ,int mid ,int end){
        int i = st ; int j = mid+1 ;
        int InvCount = 0 ;
        vector <int> temp ;

        for(int i = st ; i <= mid ; i++){
            while(j <= end && (long long)nums[i] > 2LL * nums[j]) j++ ;
            InvCount += j - (mid+1) ;
        }

        i = st , j = mid + 1 ;

        while(i <= mid && j <= end){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i]) ;
                i++ ;
            }else{
                temp.push_back(nums[j]) ;
                j++ ;
            }
        }

        while(i <= mid){
            temp.push_back(nums[i]) ; i++ ;
        }

        while(j <= end){
            temp.push_back(nums[j]) ; j++ ;
        }

        for(int idx = 0 ; idx < temp.size() ; idx++) nums[st+idx] = temp[idx] ;

        return InvCount ;
    }

    int mergeSort(vector <int>& nums, int st , int end){
        if(st < end){
            int mid = st + (end-st)/2 ;

            int leftCount = mergeSort(nums, st , mid) ;
            int rightCount = mergeSort(nums, mid+1 , end) ;

            int count = merge(nums, st, mid, end) ;

            return (count + leftCount + rightCount) ;
        }

        return 0 ;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0 , nums.size()-1) ;
    }
};