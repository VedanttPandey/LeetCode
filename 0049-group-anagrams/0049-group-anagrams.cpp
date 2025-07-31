class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> mp;
        for(auto &i:strs){
            string orig=i;
            string sortt=orig;
            sort(orig.begin(),orig.end());
            mp[orig].push_back(sortt);
        }
         vector<vector<string>> ans;
        for (auto &pair : mp) {
        ans.push_back(pair.second);
        }
        return ans;
    }
};

