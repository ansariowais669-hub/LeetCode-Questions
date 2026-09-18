#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        auto it_left = height.begin();
        auto it_right = height.end()-1;
        int maxWater = 0, currWater = 0;
        while ( it_left < it_right){
            currWater = min(*it_left,*it_right)*(right-left);
            maxWater = max( maxWater , currWater);
            if(*it_left < *it_right) {
                it_left++;
                left++;
            }else{
                it_right--;
                right--;
            }
        }
        return maxWater ;
    }
};
