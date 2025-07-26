class Solution {
public:

vector<vector<int>> vis;
void dfs(vector<vector<char>> &a,int i,int j,int n,int m){
    if(i<0 || i>=n || j<0 || j>=m || a[i][j]=='0' || vis[i][j]){
        return;
    }
    vis[i][j]=1;
    dfs(a,i+1,j,n,m);
    dfs(a,i,j+1,n,m);
    dfs(a,i,j-1,n,m);
    dfs(a,i-1,j,n,m);
}

    int numIslands(vector<vector<char>>& a) {
        int islands=0;
        int n = a.size(), m = a[0].size();
        vis.assign(n, vector<int>(m, 0));
        for(int i=0;i<a.size();++i){
            for(int j=0;j<a[0].size();++j){
                if(!vis[i][j] && a[i][j]=='1'){
                    islands++;
                    dfs(a,i,j,n,m);
                }
            }
        }
        return islands;
    }
};