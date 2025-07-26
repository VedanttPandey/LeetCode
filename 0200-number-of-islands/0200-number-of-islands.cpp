class Solution {
public:
vector<int> row={1,-1,0,0};
vector<int> col={0,0,-1,1};
queue<pair<int,int>> q;
vector<vector<int>> vis;
void bfs(vector<vector<char>> &a,int i,int j){
    q.push({i,j});
    vis[i][j]=1;

    while(!q.empty()){
        auto [r,c]=q.front();
        q.pop();

        for(int i=0;i<4;++i){
            int nr=row[i]+r,nc=c+col[i];
            if(nr>=0 && nr<a.size() && nc>=0 && nc<a[0].size() && !vis[nr][nc] && a[nr][nc]=='1'){
                vis[nr][nc]=1;
                q.push({nr,nc});
            }
        }
    }
}

    int numIslands(vector<vector<char>>& a) {
        int islands=0;
        int n = a.size(), m = a[0].size();
        vis.assign(n, vector<int>(m, 0));
        for(int i=0;i<a.size();++i){
            for(int j=0;j<a[0].size();++j){
                if(!vis[i][j] && a[i][j]=='1'){
                    islands++;
                    bfs(a,i,j);
                }
            }
        }
        return islands;
    }
};