class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans=0;
        int n1=points[0][0],n2=points[0][1];
        for(int i=1;i<points.size();++i){
            ans+=(max(abs(n2-points[i][1]),abs(n1-points[i][0])));
            n1=points[i][0],n2=points[i][1];
        }
        return ans;
    }
};