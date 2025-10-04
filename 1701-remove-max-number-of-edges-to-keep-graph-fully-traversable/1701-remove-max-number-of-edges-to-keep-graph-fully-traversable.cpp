#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct DSU {
        vector<int> parent, rank;
        int components;

        DSU(int n) {
            parent.resize(n + 1);
            rank.assign(n + 1, 1);
            components = n;
            for (int i = 1; i <= n; ++i) parent[i] = i;
        }

        int find(int x) {
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        }

        bool merge(int x, int y) {
            int first = find(x), second = find(y);
            if (first == second) return false;
            if (rank[first] > rank[second]) {
                parent[second] = first;
                rank[first] += rank[second];
            } else {
                parent[first] = second;
                rank[second] += rank[first];
            }
            components--;
            return true;
        }

        bool isConnected() { return components == 1; }
    };

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU alice(n), bob(n);
        int used = 0;

        // Type 3 edges first (shared by Alice and Bob)
        for (auto &e : edges) {
            if (e[0] == 3) {
                bool mergedA = alice.merge(e[1], e[2]);
                bool mergedB = bob.merge(e[1], e[2]);
                if (mergedA | mergedB) used++;
            }
        }

        for (auto &e : edges) {
            if (e[0] == 1 && alice.merge(e[1], e[2]))
                used++;
        }

        for (auto &e : edges) {
            if (e[0] == 2 && bob.merge(e[1], e[2]))
                used++;
        }

        if (alice.isConnected() && bob.isConnected())
            return edges.size() - used;
        return -1;
    }
};
