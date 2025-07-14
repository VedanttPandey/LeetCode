class Solution {
public:
vector<int> row={-1,1,0,0};
vector<int> col={0,0,-1,1};
queue<pair<int,int>> q;


    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int ans=0;

        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]=='1'){
                    ans++;
                    q.push({i,j});
                    grid[i][j]='0';
                    while(!q.empty()){
                        auto [l,r]=q.front();
                        q.pop();
                        for(int roww=0;roww<row.size();++roww){
                                int nr=l+row[roww],nc=r+col[roww];
                                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='1'){
                                    q.push({nr,nc});
                                    grid[nr][nc]='0';
                                }
                        }
                    }
            }
            }
        }
        return ans;
    }
};