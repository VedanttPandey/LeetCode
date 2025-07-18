class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0;
        int minL=INT_MAX;
        int sum=0;
        for(int i=0;i<nums.size();++i){
            sum+=nums[i];
            while(l<=i && sum>=target){
                minL=min(minL,i-l+1);
                sum-=nums[l];
                l++;
            }
        }

        return (minL==INT_MAX ? 0 : minL);
    }
};