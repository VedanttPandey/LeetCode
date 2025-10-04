class Solution {
public:
    struct DSU {
        vector<int> parent, rank;
        DSU(int n) {
            parent.resize(n);
            rank.assign(n, 1);
            for (int i = 0; i < n; ++i) parent[i] = i;
        }

        int find(int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }

        void merge(int x, int y) {
            int rx = find(x);
            int ry = find(y);
            if (rx == ry) return;

            if (rank[rx] > rank[ry]) {
                parent[ry] = rx;
            } else if (rank[rx] < rank[ry]) {
                parent[rx] = ry;
            } else {
                parent[ry] = rx;
                rank[rx]++;
            }
        }
    };

    vector<bool> distanceLimitedPathsExist(
        int n, 
        vector<vector<int>>& edgeList, 
        vector<vector<int>>& queries
    ) {
        sort(edgeList.begin(), edgeList.end(), 
             [](const vector<int>& a, const vector<int>& b) {
                 return a[2] < b[2];
             });

        int q = queries.size();
        vector<int> idx(q);
        iota(idx.begin(), idx.end(), 0);

        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return queries[i][2] < queries[j][2];
        });

        vector<bool> ans(q, false);
        DSU dsu(n);
        int j = 0; 

        for (int id : idx) {
            int u = queries[id][0];
            int v = queries[id][1];
            int limit = queries[id][2];

            while (j < edgeList.size() && edgeList[j][2] < limit) {
                dsu.merge(edgeList[j][0], edgeList[j][1]);
                ++j;
            }

            ans[id] = (dsu.find(u) == dsu.find(v));
        }

        return ans;
    }
};
