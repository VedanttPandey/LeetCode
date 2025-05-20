class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diffArray(n, 0);

        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            diffArray[l]++;
            if (r + 1 < n) {
                diffArray[r + 1]--;
            }
        }

        vector<int> psum(n);
        psum[0] = diffArray[0];
        for (int i = 1; i < n; ++i) {
            psum[i] = psum[i - 1] + diffArray[i];
        }

        for (int i = 0; i < n; ++i) {
            if (psum[i] < nums[i]) {
                return false;
            }
        }

        return true;
    }
};
