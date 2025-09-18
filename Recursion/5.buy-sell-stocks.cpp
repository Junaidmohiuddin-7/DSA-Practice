class Solution {
public:
    int finds(vector<int>& prices, int i, int& mini, int& maxi) {
        if (i == prices.size()) {
            return maxi;
        }
        mini = min(mini, prices[i]);
        maxi = max(maxi, prices[i] - mini);
        return finds(prices, i + 1, mini, maxi);
    }
    int maxProfit(vector<int>& prices) {
        int i = 0;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int ans = finds(prices, i, mini, maxi);
        return ans;
    }
};