class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int> mp;
        int n=s.size();
        int tail=0;
        char ch;
        int ans=INT_MIN;
        int maxFreq=-1;
        for(int r=0;r<n;++r){
            mp[s[r]]++;
            if(mp[s[r]]>maxFreq){
                maxFreq=mp[s[r]];
                ch=s[r];
            }

           while((r-tail+1)-maxFreq>k){
            mp[s[tail]]--;
            tail++;
           }

           ans=max(ans,r-tail+1);
        }
        return ans;
    }
};