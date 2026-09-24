#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector <int>& A){ // TC O(n) SC O(1)
    // find the pivot element
    int pivot = -1 ;

    for(int i = A.size()-2  ; i >= 0 ; i--){
        if(A[i] < A[i+1]){
            pivot = i ;
            break;
        }
    }
    if(pivot == -1){
        reverse(A.begin(),A.end());
        return ;
    }
    // find the element just greater than pivot element
    for( int i = A.size()-1 ; i>pivot ; i--){
        if(A[i] > A[pivot]){
            swap(A[i],A[pivot]) ;
            break;
        }
    }
        //reverse elements from pivot+1 to n-1
        reverse(A.begin()+pivot+1 , A.end()) ;
}
