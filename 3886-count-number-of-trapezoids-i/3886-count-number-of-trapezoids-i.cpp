#define ll long long
#define MOD 1000000007
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        map<ll,ll> mp;
        for(auto &i:points)mp[i[1]]++;
        vector<ll> pairs;
        for(auto &[l,r] : mp){
            if(r>=2)pairs.push_back(((r*(r-1))/2)%MOD);
        }

        ll s1=0,s2=0;
        for(auto &i:pairs){
            s1=(s1+i) % MOD;
            s2=(s2+(i*i)%MOD)%MOD;
        }
        ll ans=((s1*s1)%MOD-s2)%MOD;
        ans=ans*((MOD+1)/2)%MOD;
        return ans;
    }
};