#define ll long long
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        //a^k^k=a
        vector<ll> maxV;
        for(auto &i:nums){
            maxV.push_back((i ^ k) -i);
        }
       sort(maxV.rbegin(),maxV.rend());
       ll ans=0;
        for (int num : nums) {
            ans += num;
        }
       for(int i=0;i<maxV.size()-1;i+=2){
        if(maxV[i]+maxV[i+1]<=0)break;
        ans+=(maxV[i]+maxV[i+1]);
       }
       return ans;
    }
};