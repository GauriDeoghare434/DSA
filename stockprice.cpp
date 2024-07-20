class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int BuyPrice=prices[0];
        int profit=0;
        for(int i=0;i<prices.size();i++)
    {
        if(BuyPrice>prices[i]){
        BuyPrice=prices[i];
    }
    profit=max(profit,prices[i]-BuyPrice);
    }
    return profit;
    }
};
