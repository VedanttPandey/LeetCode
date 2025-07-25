class Solution {
public:
    bool canPartition(vector<int>& a) {
        /*
            Total sum should be equal
            if i can get (sum/2) then possible 
        */
        int n=a.size();
        int sum=accumulate(a.begin(),a.end(),0ll);
        if(sum&1)return false;
        // return true;
        
        vector<vector<bool>> dp(n+1,vector<bool> ((sum/2)+1));
        for(int i=0;i<=n;++i)dp[i][0]=true;

        for(int i=1;i<=n;++i){
            for(int j=1;j<=(sum/2);++j){
                if(a[i-1]<=j){
                    dp[i][j]=dp[i-1][j-a[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        // for(int )
        return dp[n][sum/2];
    }
};