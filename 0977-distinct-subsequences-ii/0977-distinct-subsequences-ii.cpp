#define ll long long
class Solution {
public:
    int distinctSubseqII(string s) {
       int n=s.size();
       vector<ll> dp(n+1,0);
       dp[0]=1;
       int mod=1e9+7;
       vector<ll> pre(n+1,0);
       pre[0]=1;
       int last[26];
       memset(last,-1,sizeof(last));
       for(int i=1;i<=n;++i){
            dp[i]=pre[i-1];
            if(last[s[i-1]-'a']!=-1){
                int idx=last[s[i-1]-'a'];
                dp[i]-=pre[idx];
                dp[i]%=mod;
            }
            last[s[i-1]-'a']=i-1;
            pre[i]=(pre[i-1]+dp[i]);
            pre[i]%=mod;
       } 
       return (pre[n]-1%mod+mod)%mod;
    }
};