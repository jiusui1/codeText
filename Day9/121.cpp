class Solution {
   public:
    int maxProfit(vector<int> &prices) {  //[7,1,5,3,6,4]
        int minprice = INT_MIN;
        int result = 0;
        for (int i = 0; i < prices.size(); i++) {
            result = max(result, prices[i] - minprice);
            minprice = min(minprice, prices[i]);
        }
        return result;
    }
};