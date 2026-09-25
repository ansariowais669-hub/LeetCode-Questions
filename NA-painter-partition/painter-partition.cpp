#include <bits/stdc++.h>
using namespace std;

bool isValid (vector <int>& arr , int n ,int m ,int maxAllowedTime){ // O(n)
    int painter=1 , time = 0;
    for(int i=0 ; i<n ; i++){
        if(arr[i] > maxAllowedTime) return false;
        if(time + arr[i] <= maxAllowedTime){
            time += arr[i] ;
        }else {
            painter++;
            time = arr[i] ;
        }
    }
    return painter > m ? false : true ;
}

int maxOfArray(vector <int>& arr){
    int maximum=0;
    for(int n=0 ;n<arr.size();n++) maximum = max(maximum , arr[n]) ;
    return maximum;
}

int allocateBoards(vector <int>& arr , int n, int m){ // o(logN*n) where N is range
    if(m>n) return -1 ;
    int sum = 0;
    for(int i=0 ; i<n ; i++) sum += arr[i] ; //O(n)
    int st = maxOfArray(arr) , end = sum ; 
    int ans = -1 ;

    while(st <= end){ // O(logN * n)
        int mid = st + (end - st)/2 ;

        if(isValid(arr,n,m,mid)){
            ans = mid;
            end = mid - 1;
        }else {
            st = mid + 1;
        }
    }
    return ans ;
}


int main (){
    vector <int> arr = {40,30,10,20} ;
    int n=4 , m=2;

    cout << allocateBoards(arr ,n ,m) << endl ;
    return 0;
} 
