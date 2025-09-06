#define ll long long
class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        //{1,3}-{4^1}=4
        //{4,15}-{4^2}=16
        //{16-63}-{4^3}=64

        ll tot=0;
        for(int i=0;i<queries.size();++i){
            ll start=queries[i][0],end=queries[i][1];
            // cout << "start " << start << " " << "end " << end << "\n";
            ll ans=0;
        ll num=1LL;

            for(ll j=1;j<16;++j){
                ll currNum=num*4LL*1LL;
                // cout << currNum << "\n";
                ll l=max(start,num),r=min(end,currNum-1);
                // cout << "l " << l << " " << "r " << r <<"\n";
                if(r>=l)ans+=(r-l+1)* j;
                // cout << "ans " << ans << "\n";
                num=currNum;
            }
            // cout <<"finalans " << ans << "\n";
            // ans++;
            // total+=(ans+2)
            // cout << ceil(ans+1/2)<<"\n";
            // tot+=ceil(ans+1/2);
            tot+=(ans+1)/2;
            // tot++;
        }
        return tot;
    }
};