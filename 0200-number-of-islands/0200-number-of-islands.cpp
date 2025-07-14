class Solution {
public:
vector<int> row={-1,1,0,0};
vector<int> col={0,0,1,-1};

void dfs(vector<vector<char>>& a,int i,int j,int n,int m){
    if(i<0 || i>=n || j<0 || j>=m || a[i][j]=='0'){
        return;
    }
    a[i][j]='0';
    dfs(a,i+1,j,n,m);
    dfs(a,i,j+1,n,m);
    dfs(a,i-1,j,n,m);
    dfs(a,i,j-1,n,m);
}
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size(),ans=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(grid,i,j,n,m);
                }
            }
        }
        return ans;
    }
};