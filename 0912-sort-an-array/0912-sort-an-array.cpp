class Solution {
public:
    void merge(int st ,int mid ,int end ,vector <int>& nums){
        vector <int> temp ;
        int i = st , j = mid+1 ;
        while(i <= mid && j <= end){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i]) ;
                i++ ;
            } else {
                temp.push_back(nums[j]) ;
                j++ ;
            }
        }

        while(i <= mid){
            temp.push_back(nums[i]) ; 
            i++ ;
        }
        while(j <= end){
            temp.push_back(nums[j]) ;
            j++ ;
        }

        for(int j = 0 ; j < temp.size() ; j++) nums[j+st] = temp[j] ;
    }

    void mergeSort(int st , int end , vector <int>& nums){
        if(st < end){
            int mid = st + (end-st)/2 ;

            mergeSort(st,mid,nums) ;
            mergeSort(mid+1,end,nums) ;

            merge(st,mid,end,nums) ;
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int st = 0 , end = nums.size()-1 ;
        mergeSort(st, end, nums) ;
        return nums ;
    }
};