class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      set<char> track;
        int i=0,j=0,ans=0;
        while(i<s.size() && j<s.size()){
            if (track.find(s[j]) != track.end()) {
                track.erase(s[i]);
                i++;
            } else {
                track.insert(s[j]);
                ans = max(ans, j - i + 1);
                j++;
            }
        }
        return ans;   
    }
};