class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>> pairs;
        for(int i=0;i<nums.size();++i){
            pairs.push_back({nums[i],i});
        }
        sort(pairs.begin(),pairs.end());
        vector<pair<int,int>> a;
        for(int i=pairs.size()-1;i>=0 && k>0 ;--i){
            a.push_back({pairs[i].first,pairs[i].second});
            k--;
        }

        sort(a.begin(),a.end(),[&](pair<int,int> a,pair<int,int> b){
            return a.second<b.second;
        });
        vector<int> ans;
        for(auto &[l,r] : a){
            ans.push_back(l);
        }
        return ans;
    }
};