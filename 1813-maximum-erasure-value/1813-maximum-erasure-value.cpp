class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        set<int> s;
        int l = 0, csum = 0, sum = 0;

        for (int r = 0; r < nums.size(); ++r) {
            while (s.count(nums[r])) {
                csum -= nums[l];
                s.erase(nums[l]);
                l++;
            }
            csum += nums[r];
            s.insert(nums[r]);
            sum = max(sum, csum);
        }
        return sum;
    }
};
