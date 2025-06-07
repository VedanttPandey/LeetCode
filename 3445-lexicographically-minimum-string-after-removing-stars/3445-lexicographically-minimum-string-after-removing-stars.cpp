class Solution {
public:
    string clearStars(string s) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>>> pq;
        int i=0;
        map<int,int> mp;
        while(i<s.size()){
            if(s[i]=='*' && !pq.empty()){
                mp[(pq.top().second)]=1;
                pq.pop();  
            }
            else{
                pq.push({s[i],-i});
            }
            i++;
        }
        string ans="";
       for(int i=0;i<s.size();++i){
        if(mp[-i]==1 || s[i]=='*')continue;
        ans+=s[i];
       }
       return ans;
    }
};