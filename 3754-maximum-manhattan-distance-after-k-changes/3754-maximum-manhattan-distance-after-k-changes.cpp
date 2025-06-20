class Solution {
public:
    int maxDistance(string s, int k) {
        string s1 = "", s2 = "", s3 = "", s4 = "";
        int k1 = k, k2 = k, k3 = k, k4 = k;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == 'S' && k1 > 0) {
                s1 += 'N';
                k1--;
            } else if (s[i] == 'E' && k1 > 0) {
                s1 += 'W';
                k1--;
            } else {
                s1 += s[i];
            }
        }

        for (int i = 0; i < n; i++) {
            if (s[i] == 'N' && k2 > 0) {
                s2 += 'S';
                k2--;
            } else if (s[i] == 'W' && k2 > 0) {
                s2 += 'E';
                k2--;
            } else {
                s2 += s[i];
            }
        }

        for (int i = 0; i < n; i++) {
            if (s[i] == 'S' && k3 > 0) {
                s3 += 'N';
                k3--;
            } else if (s[i] == 'W' && k3 > 0) {
                s3 += 'E';
                k3--;
            } else {
                s3 += s[i];
            }
        }

        for (int i = 0; i < n; i++) {
            if (s[i] == 'N' && k4 > 0) {
                s4 += 'S';
                k4--;
            } else if (s[i] == 'E' && k4 > 0) {
                s4 += 'W';
                k4--;
            } else {
                s4 += s[i];
            }
        }

        auto calculateDistance = [](string& s) {
            int x = 0, y = 0, maxDist = 0;
            for (char i : s) {
                if (i== 'N') y++;
                else if (i == 'S') y--;
                else if (i == 'E') x++;
                else if (i == 'W') x--;
                maxDist = max(maxDist, abs(x) + abs(y));
            }
            return maxDist;
        };

        int ans1 = calculateDistance(s1);
        int ans2 = calculateDistance(s2);
        int ans3 = calculateDistance(s3);
        int ans4 = calculateDistance(s4);

        return max({ans1, ans2, ans3, ans4});
    }
};