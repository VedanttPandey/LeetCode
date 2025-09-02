class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1;
        int ans=-1;
        while(l<r){
            int m=(l+r)>>1;
            if(nums[m]>nums[m+1] && nums[m]>nums[m-1]){
                ans=m;
                break;
            }
            else if(nums[m]>nums[m-1])l=m+1;
            else r=m;
        } 
        return ans;
    }
};