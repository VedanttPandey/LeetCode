class Solution {
public:
    char kthCharacter(int k) {
        string s="a";

        if(s.size()==k){
            return 'a';
        }

        while(s.size()<k){
            string newS;
            for(int i=0;i<s.size();++i){
                newS += (s[i] - 'a' + 1) % 26 + 'a';
            }
            s+=newS;
        }

        k--;
        char c=s[k];
        return c;
    }
};