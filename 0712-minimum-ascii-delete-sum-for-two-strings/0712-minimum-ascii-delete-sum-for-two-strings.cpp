class Solution {
public:

int dp[1005][1005];
int n,m;

int rec(int i,int j,string s1,string s2){
    if(i==n && j==m )return 0;

    if (i == n) return int(s2[j]) + rec(i, j + 1, s1, s2);

    if (j == m) return int(s1[i]) + rec(i + 1, j, s1, s2);

    if(dp[i][j]!=-1)return dp[i][j];

    int ans=INT_MAX;

    if(s1[i]!=s2[j]){
        ans=min(ans,rec(i+1,j,s1,s2)+int(s1[i]));
        ans=min(ans,rec(i,j+1,s1,s2)+int(s2[j]));
    }
    else ans=min(ans,rec(i+1,j+1,s1,s2));

    return dp[i][j]=ans;
}
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

        // return rec(0,0,s1,s2);
        return dp[0][0];
    }
};