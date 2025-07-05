class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int> mp;
        for(auto &i:arr){
            mp[i]++;
        }
        int maxi=INT_MIN;
        for(auto &[l,r] : mp){
            if(l==r)maxi=max(maxi,l);
        }
        return (maxi==INT_MIN ? -1 : maxi);
    }
};