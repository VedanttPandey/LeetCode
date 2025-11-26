class Solution {
public:
    vector<vector<vector<int>>> dp;
    int n, m, k;
    const int MOD = 1e9 + 7;

    int memo(int i, int j, int csum, vector<vector<int>>& grid) {

        csum %= k;     
        int r = csum;  

        if (i == n - 1 && j == m - 1) {
            return ((r + grid[i][j]) % k == 0);
        }

        if (dp[i][j][r] != -1) return dp[i][j][r];

        long long ans = 0;

        if (i + 1 < n) {
            ans += memo(i + 1, j, r + grid[i][j], grid);
            ans %= MOD;
        }

        if (j + 1 < m) {
            ans += memo(i, j + 1, r + grid[i][j], grid);
            ans %= MOD;
        }

        return dp[i][j][r] = ans;
    }

    int numberOfPaths(vector<vector<int>>& grid, int K) {
        k = K;
        n = grid.size();
        m = grid[0].size();

        dp.assign(n, vector<vector<int>>(m, vector<int>(k, -1)));

        return memo(0, 0, 0, grid);
    }
};
