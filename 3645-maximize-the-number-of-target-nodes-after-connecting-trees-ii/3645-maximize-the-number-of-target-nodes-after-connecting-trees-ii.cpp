const int maxn = 100005+20;
int dp[maxn][2], n;
class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        const int n = edges1.size(), m = edges2.size();
        vector<vector<int>> g1(n+1), g2(m+1);
        for(auto &edge : edges1) {
            g1[edge[0]].push_back(edge[1]);
            g1[edge[1]].push_back(edge[0]);
        }
        for(auto &edge : edges2) {
            g2[edge[0]].push_back(edge[1]);
            g2[edge[1]].push_back(edge[0]);
        }
        memset(dp,0,sizeof(dp));
        auto dfs = [&](auto &&self, int u, int par, vector<vector<int>> &g) -> void {
            dp[u][0] = 1;
            dp[u][1] = 0;
            for(auto &v : g[u]) {
                if(v != par) {
                    self(self, v, u, g);
                    dp[u][0] += dp[v][1];
                    dp[u][1] += dp[v][0];
                }
            }
        };
        auto reDFS = [&](auto &&self, int u, int par, vector<vector<int>> &g) -> void {
            for(auto &v : g[u]) {
                if(v != par) {
                    int u_even = dp[u][0] - dp[v][1];
                    int u_odd = dp[u][1] - dp[v][0];
                    dp[v][0] += u_odd;
                    dp[v][1] += u_even;
                    self(self, v, u, g);
                }
            }  
        };
        dfs(dfs, 0, -1, g2);
        reDFS(reDFS, 0, -1, g2);
        int bestOdd = 0;
        for(int i = 0; i <= m; ++i) bestOdd = max(bestOdd, dp[i][1]);
        memset(dp,0,sizeof(dp));
        dfs(dfs, 0, -1, g1);
        reDFS(reDFS, 0, -1, g1);
        vector<int> ans;
        for(int i = 0; i <= n; ++i) {
            int res = dp[i][0] + bestOdd;
            ans.push_back(res);
        }
        return ans;
    }
};