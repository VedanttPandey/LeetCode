class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        
        vector<vector<int>> adj1(n), adj2(m);
        for (auto& e : edges1) {
            adj1[e[0]].push_back(e[1]);
            adj1[e[1]].push_back(e[0]);
        }
        for (auto& e : edges2) {
            adj2[e[0]].push_back(e[1]);
            adj2[e[1]].push_back(e[0]);
        }

        auto bfs = [&](vector<vector<int>>& adj, int start, int limit) {
            vector<bool> visited(adj.size(), false);
            queue<pair<int, int>> q;
            visited[start] = true;
            q.push({start, 0});
            int count = 0;
            while (!q.empty()) {
                auto [node, dist] = q.front(); q.pop();
                if (dist > limit) continue;
                count++;
                for (int nei : adj[node]) {
                    if (!visited[nei]) {
                        visited[nei] = true;
                        q.push({nei, dist + 1});
                    }
                }
            }
            return count;
        };

        vector<int> answer(n, 0);

        // Precompute all tree2 BFS counts for every root
        vector<int> tree2Counts(m);
        for (int i = 0; i < m; ++i) {
            tree2Counts[i] = bfs(adj2, i, k - 1);
        }

        for (int i = 0; i < n; ++i) {
            int localCount = bfs(adj1, i, k);
            int maxCount = 0;
            for (int j = 0; j < m; ++j) {
                maxCount = max(maxCount, localCount + tree2Counts[j]);
            }
            answer[i] = maxCount;
        }

        return answer;
    }
};
