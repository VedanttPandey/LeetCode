class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=INT_MIN;
        int cur=INT_MAX;
        for(int i=0;i<prices.size();++i){
            cur=min(cur,prices[i]);
            if(prices[i]>cur){
            ans=max(ans,prices[i]-cur);
            }
        }
        return max(0,ans);
    }
};