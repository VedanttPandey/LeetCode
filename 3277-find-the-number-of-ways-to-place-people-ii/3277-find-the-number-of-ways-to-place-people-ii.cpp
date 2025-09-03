class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [&](vector<int> &a, vector<int> &b) {
            return (a[0]==b[0])?a[1]<b[1]:a[0]>b[0];
        });

        int cnt = 0;
        int n = points.size();

        for (int i = 0; i < n-1; i++) {
             int y=INT_MAX;
            for(int j = i+1; j<n; j++){
                if (points[j][1]>=points[i][1] && y>points[j][1]){
                    cnt++;
                    y=points[j][1];
                }
            }
        }

        // for (auto &p : points) {
        //     cout << p[0] << " " << p[1] << "\n";
        // }

        return cnt;
    }
};
