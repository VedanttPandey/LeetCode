class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,long long> mp;
        long long ans=0;
        for(auto &i : words){
           string rev="";
           rev+=i[1];rev+=i[0];
            if(mp[rev]){
                ans+=4;
                mp[rev]--;
            }
            // else if(mp[rev] && rev[0]==rev[1]){
            //     ans+=2;
            //     mp[rev]--;
            // }
            else{
                mp[i]++;
            }
        }
        for(auto &[l,r] :mp){
            if(l[0]==l[1] && r>0){ans+=2;break;}
        }
        return ans;
    }
};