class Solution {
public:

vector<int> dx={0,0,1,-1};
vector<int> dy={1,-1,0,0};
void bfs(vector<vector<int>> &grid,vector<vector<int>> &dist,int n,int m){
    deque<pair<int,int>> dq;
    dq.push_back({0,0});
    while(!dq.empty()){
        auto [l,r] =dq.front();
        dq.pop_front();
        for(int k=0;k<4;++k){
            int nr=l+dx[k],nc=r+dy[k];
            int cost=(k+1==grid[l][r] ? 0 : 1);
            if(nr>=0 && nr<n && nc>=0 && nc<m && dist[nr][nc]>dist[l][r]+cost){
                dist[nr][nc]=dist[l][r]+cost;
                if(cost)dq.push_back({nr,nc});
                else dq.push_front({nr,nc});
            }
        }
    }
}
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> dist(n,vector<int> (m,1e9));

        // for(int i=0;i<n;++i){
        //     for(int j=0;j<m;++j){
        //         cout << dist[i][j] << "\t";
        //     }
        //     cout << "\n";
        // }
        dist[0][0]=0;

        bfs(grid,dist,n,m);
        return dist[n-1][m-1];
    }
};