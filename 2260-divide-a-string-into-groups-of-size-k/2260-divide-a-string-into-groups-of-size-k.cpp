class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int l=0;
        while(l+k<=s.size()){
            ans.push_back(s.substr(l,(k)));
            l+=k;
        }
        cout<<l<<" ";
        if(s.size()%k!=0){
            int lastIdx=s.size()-(s.size()%k);
            string f;
            int cnt=0;
            for(int i=lastIdx;i<s.size();++i){
                f+=s[i];
                cnt++;
            }
            while(cnt!=k){
                f+=fill;
                cnt++;
            }
            ans.push_back(f);
        }
        return ans;
    }
};