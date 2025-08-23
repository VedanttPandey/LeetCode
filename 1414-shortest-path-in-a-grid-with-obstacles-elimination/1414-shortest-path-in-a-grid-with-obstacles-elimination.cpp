class Solution {
public:
    int dist[41][41][40*41+1];
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};


    bool isValid(int i,int j,int n,int m){
        return (i>=0 && i<n && j>=0 && j<m);
    }

    void bfs(int i,int j,vector<vector<int>>& grid,int n,int m,int k){
        deque<tuple<int,int,int>> dq;
        dq.push_back({0,0,0});
        dist[0][0][0]=0;

        while(!dq.empty()){
            auto [currR,currC,destroyed]=dq.front();
            dq.pop_front();

            for(int d=0; d<4; ++d){
                int nr=currR+dx[d], nc=currC+dy[d];
                if(isValid(nr,nc,n,m)){
                    int nwall=destroyed + grid[nr][nc];
                    if(nwall<=k && dist[nr][nc][nwall]>dist[currR][currC][destroyed]+1){
                        dist[nr][nc][nwall]=dist[currR][currC][destroyed]+1;
                        dq.push_back({nr,nc,nwall});
                    }
                }
            }
        }
    }

    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size(), m=grid[0].size();

        for(int a=0;a<n;a++){
            for(int b=0;b<m;b++){
                for(int c=0;c<=k;c++){
                    dist[a][b][c]=1e9;
                }
            }
        }

        bfs(0,0,grid,n,m,k);

        int ans=1e9;
        for(int used=0; used<=k; used++){
            ans=min(ans, dist[n-1][m-1][used]);
        }
        return (ans==1e9 ? -1 : ans);
    }
};
