class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0,bestbuy=prices[0];
        int n=prices.size();
        for(int i=0;i<n;i++){
             maxprofit=max(maxprofit,prices[i]-bestbuy);
             bestbuy=min(bestbuy,prices[i]);
        }
        return maxprofit;
    }
};
