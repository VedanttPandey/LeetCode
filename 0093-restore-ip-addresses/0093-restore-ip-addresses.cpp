class Solution {
public:
vector<string> ans;
string curr;


vector<string> split(string a,char ch){
    vector<string> res;
    stringstream ss (a);
    string item;

    while(getline(ss,item,ch)){
        res.push_back(item);
    }
    return res;
}

bool isValid(string ip){
    vector<string> check=split(ip,'.');
    if(check.size()<4)return false;
    for(auto &i:check){
        if(i.size()>1 && i[0]=='0')return false;
        long long num=stoll(i);
        if(num>255)return false;
    }
    return true;
}
void rec(int level,int k,string &s){
    //bc
    if(level==s.size()){
        if(k==3 && isValid(curr)){
            ans.push_back(curr);
        }
        return;
    }
    //take num
    curr+=s[level];
    rec(level+1,k,s);
    curr.pop_back();
    //take num with a dot
    if(k<3){
    curr+=s[level];
    curr+='.';
    rec(level+1,k+1,s);
    curr.pop_back();
    curr.pop_back();
    }
}
    vector<string> restoreIpAddresses(string s) {
        rec(0,0,s);
        return ans;
    }
};