#define ll long long
class Solution {
public:
    int change(int amount, vector<int>& coins) {
       vector<unsigned ll> dp(amount+1,0);
        dp[0]=1;
        for(ll coin:coins){
            for(ll i=coin;i<=amount;++i){
                dp[i]+=dp[i-coin];
            }
        }
       return dp[amount];
    }
};