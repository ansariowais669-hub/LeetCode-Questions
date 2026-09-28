#include<bits/stdc++.h>
using namespace std;

vector <int> pairsum (vector <int> &nums,int pairsum){
    vector <int> ans;
    auto it_1 = nums.begin();
    auto it_2 = nums.end()--;
    int sum = 0;
    while(sum != pairsum){
        sum = *(it_1) + *(it_2) ;
        if(sum < pairsum) *(it_1)++;
        if(sum>pairsum) *(it_2)--;
    }
    ans.push_back(*(it_1));
    ans.push_back(*(it_2));
    return ans ;
}

int main(){
    vector <int> nums = {2,7,11,15} ;
    int target = 9;
    vector <int> ans = pairsum(nums , target);
    cout << ans[0] << " " << ans[1] ;
    return 0;
}
