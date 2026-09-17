#include <iostream>
#include <vector>
using namespace std;

bool isValid (vector <int>& arr , int n ,int m ,int maxAllowedPages){ // O(n)
    int st=1 , pages = 0;
    for(int i=0 ; i<n ; i++){
        if(arr[i] > maxAllowedPages) return false;
        if(pages + arr[i] <= maxAllowedPages){
            pages += arr[i] ;
        }else {
            st++;
            pages = arr[i] ;
        }
    }
    return st > m ? false : true ;
}

int allocateBooks(vector <int>& arr , int n, int m){ // o(logN*n) where N is range
    if(m>n) return -1 ;
    int sum = 0;
    for(int i=0 ; i<n ; i++) sum += arr[i] ; //O(n)
    int st = 0 , end = sum ; 
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
    vector <int> arr = {15,17,20} ;
    int n=3 , m=2;

    cout << allocateBooks(arr ,n ,m) << endl ;
    return 0;
} 
