class Solution {
public:
    int maxDifference(string s) {
        map<char,int> mp;
        for(auto &i:s)mp[i]++;
        int maxOdd=INT_MIN,maxEven=INT_MIN,minOdd=INT_MAX,minEven=INT_MAX;
        for(auto &[l,r] : mp){
            if(r&1){
                maxOdd=max(maxOdd,r);
                minOdd=min(minOdd,r);
            }
            else{
                maxEven=max(maxEven,r);
                minEven=min(minEven,r);
            }
        }

        return (maxOdd-minEven);
    }
};