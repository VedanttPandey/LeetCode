class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxDiff=-1;
        int mini=nums[0],maxi=nums[0];

       for(int i=1;i<nums.size();++i){
        if(nums[i]>mini){maxDiff=max(maxDiff,abs(mini-nums[i]));
        }
        else mini=min(mini,nums[i]);
       }

        return max(-1,maxDiff);
    }
};