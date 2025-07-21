class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        vector<vector<int>> dp(coins.size()+1,vector<int> (amount+1,INT_MAX));
        for(int i=0;i<=coins.size();++i)dp[i][0]=0;
        for(int i=1;i<=coins.size();++i){
            for(int j=1;j<=amount;++j){
                //how many min iTH coins i need for jTH amount
                /*
                    dp[i][j]===????
                    dp[i][j]=dp[i-1][j]
                    jth amount by ith Coin
                    dp[i][j]==INT_MAX && j>=coins[i-1]
                    d[i][j]=min(dp[i][j],dp[i-1][j]+1)
                */            
                dp[i][j]=dp[i-1][j];
                if(j>=coins[i-1] &&  dp[i][j-coins[i-1]]!=INT_MAX ){
                    dp[i][j] = min(dp[i][j], dp[i][j - coins[i-1]] + 1);
                }
            }
        }

        return (dp[coins.size()][amount]==INT_MAX ? -1 : dp[coins.size()][amount]);
    }
};
/*
    dp[i][j]--> min number of iCoins for jAmount
    dp[i][j-1]--> min number of Icoins for (j-1)Amount
    dp[i-1][j]--> min number of (i-1)Coins for JthAmount
    dp[i-1][-1j]--> min number of (i-1)Coins for (J-1)thAmount
*/