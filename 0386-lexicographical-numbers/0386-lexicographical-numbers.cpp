class Solution {
public:
    void dfs(int cur,int n,vector<int>& res){
        if(cur > n){
            return;
        }
        res.push_back(cur);
        for(int i=0;i<=9;i++){
            int new_num = (cur*10)+i;
            if(new_num > n){
                return;
            }
            dfs(new_num,n,res);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int>res;
        for(int i=1;i<=9;i++){
            dfs(i,n,res);
        }
        return res;
    }
};