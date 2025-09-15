class Solution {
public:
    int n;
    string s;
    set<string> dict;
    vector<int> dp;  

    bool rec(int idx) {
        if (idx == n) return true;  
        if (dp[idx] != -1) return dp[idx];

        for (int end = idx; end < n; end++) {
            string sub = s.substr(idx, end - idx + 1);
            if (dict.count(sub) && rec(end + 1)) {
                return dp[idx] = 1;
            }
        }
        return dp[idx] = 0;
    }

    bool wordBreak(string str, vector<string>& wordDict) {
        s = str;
        n = s.size();
        dict.clear();
        for (auto &w : wordDict) dict.insert(w);

        dp.assign(n, -1);
        return rec(0);
    }
};
