class Solution {
public:
vector<int> vis;

bool isBipartitee=true;
void dfs(vector<vector<int>> &graph,int i,int color){
    vis[i]=3-color;
    for(auto &e:graph[i]){
        if(!vis[e]){
            dfs(graph,e,3-color);
        }
        else{
            if(vis[e]==vis[i]){
                isBipartitee=false;
            }
        }
    }
    // return isBipartitee;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        int color=1;
        vis.assign(n,0);
        for(int i=0;i<n;++i){
            if(!vis[i]){
                dfs(graph,i,color);
            }
        }
        return isBipartitee;
    }
};