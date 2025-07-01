class Solution {
public:
    int possibleStringCount(string word) {
        vector<int> conse;
        int n=word.size();
        int cnt=n;
        for(int i=1;i<n;++i){
            if(word[i]!=word[i-1]){
                cnt--;
            }
            // else cnt++;
        }
        return cnt;
    }
};