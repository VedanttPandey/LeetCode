class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<int> in(n);
        for(vector<int> &edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            in[v]++;
        }

        queue<int> q;
        for(int i = 0; i<n;i++){
            if(in[i] == 0){
                q.push(i);
            }
        }
        
        set<int> colorSet;
        for(char c: colors)
            colorSet.insert(c - 'a');

        vector<vector<int>> dp(n, vector<int>(26));
        int cnt = 0, ans = 0;
        while(!q.empty()){
            int u = q.front();
            int c = colors[u] - 'a';
            dp[u][c]++;
            ans = max(ans, dp[u][c]);
            cnt++;
            q.pop();
            for(int v: adj[u]){
                for(int k: colorSet){
                    dp[v][k] = max(dp[v][k], dp[u][k]);
                }
                in[v]--;
                if(in[v] == 0)
                    q.push(v);
            }
        }
        return cnt == n ? ans : -1;
    }
};