#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector <int>& arr ,int N, int C, int minAllowedDistance){ //O(N)
    int cows = 1, lastStallPosition = arr[0] ;

    for(int i=0 ; i<N ; i++){
        if(arr[i]-lastStallPosition >= minAllowedDistance){
            cows++;
            lastStallPosition = arr[i] ;
        }
        if(cows == C) return true ;
    }
    return false ;
}


int getDistance(vector <int>& arr , int N, int C){ // o(logN*n) where N is range
    sort(arr.begin(),arr.end()); // NlogN
    int st=1 , end = arr[N-1] - arr[0] ,ans = -1 ;

    while(st<=end){ // O(log(range)*N)
        int mid = st + (end-st)/2 ;

        if(isPossible(arr ,N ,C ,mid)) {
            ans = mid;
            st = mid+1 ;
        } else end = mid-1 ;
    }
    return ans ;
}


int main (){
    vector <int> arr = {1,2,8,4,9} ;
    int n=5 , m=3;

    cout << getDistance(arr ,n ,m) << endl ;
    return 0;
} 
