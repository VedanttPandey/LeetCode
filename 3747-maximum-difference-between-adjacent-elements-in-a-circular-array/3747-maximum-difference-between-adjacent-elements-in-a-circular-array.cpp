class Solution {
public:
    int maxAdjacentDistance(vector<int>& a) {
        int ans=abs(a[0]-a[a.size()-1]);
        for(int i=1;i<a.size();++i){
            ans=max(ans,abs(a[i]-a[i-1]));
        }
        return ans;
    }
};