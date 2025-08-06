class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int l = 0;

        for (int r = 0; r <= n; ++r) {
            if (r == n || s[r] == ' ') {
                int start = l, end = r - 1;
                while (start < end) {
                    swap(s[start], s[end]);
                    ++start;
                    --end;
                }
                l = r + 1;
            }
        }
        return s;
    }
};
