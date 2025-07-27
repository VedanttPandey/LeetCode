class Solution {
public:
    bool dfs(vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &pathVis, int i) {
        vis[i] = true;
        pathVis[i] = true;

        for (auto &x : adj[i]) {
            if (!vis[x]) {
                if (dfs(adj, vis, pathVis, x)) {
                    return true;
                }
            } else if (pathVis[x]) {
                return true;
            }
        }

        pathVis[i] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& p) {
        vector<vector<int>> adj(numCourses);
        vector<bool> vis(numCourses, false);
        vector<bool> pathVis(numCourses, false);

        for (auto &l : p) {
            adj[l[1]].push_back(l[0]); }

        for (int i = 0; i < numCourses; ++i) {
            if (!vis[i]) {
                if (dfs(adj, vis, pathVis, i)) {
                    return false; 
                }
            }
        }

        return true; 
    }
};
