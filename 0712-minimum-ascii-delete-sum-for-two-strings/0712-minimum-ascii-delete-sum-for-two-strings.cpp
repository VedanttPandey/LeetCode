class Solution {
public:

int dp[1005][1005];
int n,m;
    int minimumDeleteSum(string s1, string s2) {
        memset(dp,-1,sizeof(dp));

        n=s1.size(),m=s2.size();

        for(int i=n;i>=0;--i){
            for(int j=m;j>=0;--j){
                if(i==n && j==m)dp[i][j]=0;
                else if (i == n) {
                    dp[i][j] = int(s2[j]) + dp[i][j+1];
                }
                else if (j == m) {
                    dp[i][j] = int(s1[i]) + dp[i+1][j];
                }
                else{
                    if(s1[i]!=s2[j]){
                        dp[i][j]=min(dp[i+1][j]+int(s1[i]),dp[i][j+1]+int(s2[j]));
                    }
                    else dp[i][j]=(dp[i+1][j+1]);
                }
            }
        }

        return dp[0][0];
    }
};