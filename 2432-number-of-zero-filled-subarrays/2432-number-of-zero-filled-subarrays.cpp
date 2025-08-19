#define ll long long
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        ll ans=0;
        ll curr=0;
        for(auto &i:nums){
            if(i!=0){
                ans+=(curr*(curr+1))/2;
                curr=0;
            }
            else curr++;
        }
        if(curr!=0)ans+=(curr*(curr+1))/2;
        return ans;
    }
};