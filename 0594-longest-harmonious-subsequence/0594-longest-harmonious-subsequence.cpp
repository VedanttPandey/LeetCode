class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        map<int,int> mp;
        for(auto &i:nums)mp[i]++;
        int ans=0;
        for(int i=0;i<nums.size()-1;++i){
            if(abs(nums[i]-nums[i+1])==1){
                ans=max(ans,mp[nums[i]]+mp[nums[i+1]]);
            }
        }
        return ans;
    }
};