#include <bit>
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1,0);
        dp[0]=0;
        if(n==0)return {0};
        if(n==1)return {0,1};
        dp[1]=1;

        for(int i=2;i<=n;++i){
            dp[i]=dp[i>>1]+dp[i&1];
        }
        // for(int i=0;i<=n;++i){
        //     cout<<dp[i]<<" ";
        // }
        return dp;
    }
};
/*
    0->0000
    1->0001
    2->0010
    3->0011
    4->0100
    5->0101
    6->0110
    7->0111
    8->1000
    9->1001
*/