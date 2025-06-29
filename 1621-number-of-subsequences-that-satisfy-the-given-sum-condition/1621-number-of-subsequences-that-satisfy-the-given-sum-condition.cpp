const int MOD=1e9+7;
#define ll long long
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        ll cnt=0;
        ll n=nums.size();
        sort(nums.begin(),nums.end());
        ll l=0,r=n-1;
        vector<ll> power(n+1);
        //DUMB..DUMB...DUMBO.....
        power[0]=1;
        for(ll i=1;i<=n;++i){
            power[i]=(power[i-1]*2LL)%MOD;
        }
        while(l<=r){
            if(nums[l]+nums[r]<=target){
                // cnt=(cnt+(1<<(r-l)))%MOD;
               cnt=(cnt+(power[r-l])%MOD)%MOD;
                l++;
            }
            else{
                r--;
            }
        }
        return cnt;
    }
};