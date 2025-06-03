class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        queue<int> q;
        for (auto &i : initialBoxes) q.push(i);

        int maxCandies = 0;
        vector<int> key(n, 0), taken(n, 0);
        vector<bool> visited(n, false);

        for (int i = 0; i < n; ++i) key[i] = status[i];

        while (!q.empty()) {
            int top = q.front();
            q.pop();

            if (visited[top]) continue;

            if (key[top] == 0) {
                taken[top] = 1;
                continue;
            }

            visited[top] = true;
            maxCandies += candies[top];
            taken[top] = 1;

            for (auto &i : containedBoxes[top]) {
                q.push(i);  
            }

            for (auto &i : keys[top]) {
                if (key[i] == 0) {
                    key[i] = 1;
                    if (taken[i] && !visited[i]) {
                        q.push(i);  
                    }
                }
            }
        }

        return maxCandies;
    }
};
