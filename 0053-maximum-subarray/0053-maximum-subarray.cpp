class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cSum=0,maxSum=INT_MIN;
        for(auto &i:nums){
            cSum+=i;
            maxSum=max(maxSum,cSum);
            cSum=max(cSum,0);
        }
        // cout << cSum << " " << maxSum;
        return maxSum;
    }
};