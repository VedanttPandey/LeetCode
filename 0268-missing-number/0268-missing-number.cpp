class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cur=0;

        for(auto &i:nums){
            if(i!=cur)return cur;
            cur++;
        }
        return cur;
    }
};