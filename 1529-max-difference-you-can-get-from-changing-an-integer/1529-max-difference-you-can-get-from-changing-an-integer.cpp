class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        int idx = -1;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != '9') {
                idx = i;
                break;
            }
        }

        int n = s.size();
        string forMax;

        if (idx != -1) {
            for (int i = 0; i < n; ++i) {
                if (s[i] == s[idx]) forMax += '9';
                else forMax += s[i];
            }
        } else {
            forMax = s; 
        }

        idx = -1;
        string forMin;

        if (s[0] != '1') {
            for (int i = 0; i < n; ++i) {
                forMin += (s[i] == s[0] ? '1' : s[i]);
            }
        } else {
            for (int i = 1; i < n; ++i) {
                if (s[i] != '0' && s[i] != '1') {
                    idx = i;
                    break;
                }
            }
            if (idx != -1) {
                for (int i = 0; i < n; ++i) {
                    forMin += (s[i] == s[idx] ? '0' : s[i]);
                }
            } else {
                forMin = s; 
            }
        }

        return stoi(forMax) - stoi(forMin);
    }
};
