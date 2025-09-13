class Solution {
public:
// int dp[1001][2001];
int mod=1e9+7;
vector<vector<int>> dp;

int rec(int i,int pos,int endPos,int k,int startPos){
    if(i==k){
        if(pos!=endPos)return 0;
        else return 1;
    }

    if(dp[i][pos-(startPos-k)]!=-1){
        return dp[i][pos-(startPos-k)];
    }

    int ans=0;
    ans+=rec(i+1,pos-1,endPos,k,startPos) + rec(i+1,pos+1,endPos,k,startPos);
    ans%=mod;
    return dp[i][pos-(startPos-k)]=ans;
}
    int numberOfWays(int startPos, int endPos, int k) {
        /*
            given n points have to decide L/R at each point
            F1
            State-{
                (i,pos)
            }

            Transi-{
                rec(i+1,pos-1){left} + rec(i+1,pos+1){right}
            }
        */
        dp.clear();
        dp.resize(k,vector<int> (2*k+1,-1));
        // memset(dp,-1,sizeof(dp));
       return rec(0,startPos,endPos,k,startPos);
    }
};