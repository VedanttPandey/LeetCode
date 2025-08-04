#define ll long long
class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        deque<ll> q(nums.begin(),nums.end());
        ll ans=0;
        while(q.size()>=3){
            ll last=q.back();q.pop_back();
            ll slast=q.back();q.pop_back();
            ll first=q.front();q.pop_front();
            ans+=slast;
        }
        return ans;
    }
};