class Solution {
public:
    int coinss(vector<int>& coins, int amount) {

        if (amount == 0) {
            return 0;
        }
        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            int coin = coins[i];
            if (coin <= amount) {
                int recans = coinss(coins,amount-coin);
                if (recans != INT_MAX) {
                    recans = 1 + recans;
                    mini = min(recans, mini);
                }
            }
        }
        return mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans= coinss(coins, amount);
         if(ans==INT_MAX){
            return -1;
         }
         else{
            return ans;
         }
         
          }
};