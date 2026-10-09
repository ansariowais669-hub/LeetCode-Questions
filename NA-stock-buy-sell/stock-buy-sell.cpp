#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        auto it = prices.begin();
        int maxProfit = 0 , bestBuy = *it;
        for(;it!=prices.end();it++){
            if(*it < bestBuy) bestBuy = *it;
            if(*it > bestBuy){
                maxProfit = max( maxProfit , *it - bestBuy);
            }
        }
        return maxProfit;
    }
};
