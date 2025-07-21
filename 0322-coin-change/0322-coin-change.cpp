class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT_MAX);
        dp[0]=0;
        for(auto &i:coins){
            for(int j=1;j<=amount;++j){
                if(j>=i && dp[j-i]!=INT_MAX){
                    dp[j]=min(dp[j],dp[j-i]+1);
                }
            }
        }
        return (dp[amount]==INT_MAX ? -1 : dp[amount]);
    }
};