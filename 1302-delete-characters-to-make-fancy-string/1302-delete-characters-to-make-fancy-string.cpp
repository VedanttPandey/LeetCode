class Solution {
public:
    string makeFancyString(string s) {
        int l = 0, r = 0;
        int n = s.size();
        int cnt = 1;
        string ans;
        for (; r < n; ++r) {
            if (s[r] == s[l]) {
                cnt++;
            } else {
                if (cnt >= 3) {
                    ans += s[l];
                    ans += s[l];
                } else {
                    for (int i = l; i < r; ++i) {
                        ans += s[i];
                    }
                }
                l = r;
                cnt = 1;
            }
        }
        if (cnt >= 3) {
            ans += s[l];
            ans += s[l];
        } else {
            for (int i = l; i < n; ++i) {
                ans += s[i];
            }
        }
        return ans;
    }
};
