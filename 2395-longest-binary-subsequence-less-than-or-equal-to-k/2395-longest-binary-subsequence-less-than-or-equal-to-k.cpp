#define ll long long
class Solution {
public:
    int longestSubsequence(string s, ll k) {
        ll ans=0;
        ll val=0,pos=0;
        for(int i=s.size()-1;i>=0;--i){
            if(s[i]=='1'){
                if(pos>32 || val+(1LL<<(pos))>k){
                    continue;
                }
                ans++;
                val+=(1LL<<pos);
                pos++;
            }
            else{
                ans++;
                pos++;
            }
        }
        return ans;
    }
};