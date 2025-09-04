class Solution {
public:

bool finished=false;
string curr;
string ans;
void rec(int level,string &s,set<int> &temp){
    if(finished)return;
    if(level==s.size()+1){
        ans=curr;
        finished=true;
        return;
    }

    set<int> numb=temp;

    for(auto &i:numb){
        if(level==0 || s[level-1]=='I' && i>(curr.back()-'0') || s[level-1]=='D' && i<(curr.back()-'0')){
            curr+='0'+i;
            temp.erase(i);
            rec(level+1,s,temp);
            curr.pop_back();
            temp.insert(i);
        }
    }
    
}
    string smallestNumber(string pattern) {
        set<int> temp;

        for(int i=1;i<=(pattern.size()+1);++i)temp.insert(i);
        rec(0,pattern,temp);

        return ans;
    }
};