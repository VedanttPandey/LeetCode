#define ll long long
class Solution {
public:
    int maxFreeTime(int eT, vector<int>& s, vector<int>& e) {
        int n=s.size();
        vector<ll> gap(1,s[0]);
        for(int i=1;i<n;++i){
            gap.push_back(s[i]-e[i-1]);
        }
        gap.push_back(eT-e[n-1]);

        
        for(auto &i:gap)cout<<i<<" ";
        cout<<"\n";
        
        vector<ll> right(gap.size(),0);

        for(int i=gap.size()-2;i>=0;--i){
            right[i]=max(right[i+1],gap[i+1]);
        }
        for(auto &i:right)cout<<i<<" ";
        cout<<"\n";
        ll ans=0;
        ll left=0;
        for(int i=1;i<gap.size();++i){
            ll gaps=e[i-1]-s[i-1];
            ll rightt=right[i];
            if(gaps<=max(left,rightt)){
                ans=max(ans,gaps+gap[i]+gap[i-1]);
            }
            ans=max(ans,gap[i-1]+gap[i]);
            left=max(left,gap[i-1]);
            // cout<<e[i-1]<<" "<<s[i-1]<<" "<<i<<" "<<rightt<<" "<<left<<"\n";
            // cout<<"gaps-->"<<gaps+left+rightt<<"\n";
            // cout<<"ans"<<ans<<"\n";
        }
        return ans;
    }
};

