class Solution {
public:
    void dfs(vector<int> &edges, vector<int> &distances, int node, vector<bool> &vis, int dist) {
        vis[node] = true;
        distances[node] = dist;
        int curr = edges[node];
        if (curr != -1 && !vis[curr]) {
            dfs(edges, distances, curr, vis, dist + 1);
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, -1), dist2(n, -1);  
        vector<bool> vis1(n, false), vis2(n, false);

        dfs(edges, dist1, node1, vis1, 0);
        dfs(edges, dist2, node2, vis2, 0);

        int minDist = INT_MAX, ans = -1;
        for (int i = 0; i < n; ++i) {
            if (dist1[i] != -1 && dist2[i] != -1) {
                int maxDist = max(dist1[i], dist2[i]);
                if (maxDist < minDist) {
                    minDist = maxDist;
                    ans = i;
                }
            }
        }
        return ans;
    }
};
