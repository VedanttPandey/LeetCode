class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n-2;++i){
            if(i>0 && nums[i]==nums[i-1])continue;
            int target=-nums[i];
            int l=i+1,r=n-1;

            while(l<r){
                int sum=nums[l]+nums[r];
                if(sum==target){
                    ans.push_back({nums[l],nums[r],nums[i]});
                    l++;r--;
                    while(l<r && nums[l]==nums[l-1])l++;
                    while(r>l && nums[r]==nums[r+1])r--;
                } 
                else if(nums[l]+nums[r]<target)l++;
                else r--;
            }
        }
        return ans;
    }
};