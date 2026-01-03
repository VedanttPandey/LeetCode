class Solution {
public:
int mod=1e9+7;
int dp[5001][4][4][4];
int rec(int i,int c1,int c2,int c3,int n){
    if(i==(n))return 1;
    if(dp[i][c1][c2][c3]!=-1)return dp[i][c1][c2][c3];

    int ways=0;

    for(int cl1=1;cl1<=3;++cl1){
        if(c1!=cl1){
        for(int cl2=1;cl2<=3;++cl2){
            if(cl2!=c2 && cl2!=cl1)

            {for(int cl3=1;cl3<=3;++cl3){
                if(cl3!=c3 && cl3!=cl2)ways=(ways+rec(i+1,cl1,cl2,cl3,n))%mod;
            }}
        }
        }
    }
    return dp[i][c1][c2][c3]=ways;
}
    int numOfWays(int n) {
        if(n==1)return 12;
        memset(dp,-1,sizeof(dp));
        return rec(0,0,0,0,n);
    }
};
