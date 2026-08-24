class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int profit=0;
        int mini=prices[0];
        for(int num: prices){
            mini=min(mini,num);
            profit=max(profit,num-mini);
        }
        return profit;
    }
};