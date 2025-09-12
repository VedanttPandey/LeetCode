class Solution {
public:
int n;
int dp[500001][4];

int rec(int level,int currentLane,vector<int>& obstacles){
    //Base Case
    if(level==(n-1)){
        return 0;
    }
    //cache
    if(dp[level][currentLane]!=-1)return dp[level][currentLane];

    //transition
    int ans=1e9;

    if(obstacles[level+1]!=currentLane){
        //can staye here
        ans=min(ans,rec(level+1,currentLane,obstacles));
    }
    else{
        for(int i=1;i<=3;++i){
            if(i!=currentLane && obstacles[level]!=i){
                ans=min(ans,1+rec(level+1,i,obstacles));
            }
        }
    }


    //S&R
    return (dp[level][currentLane]=ans);
}
    int minSideJumps(vector<int>& obstacles) {
        /*
            Form -> 2

            State -> {
                (level,currentlANE)--> min number of steps till ith level of currentLane
            } 

            Transition -> {
                if(obstacles[level]!=0 && currentLane=obstacles[level]){
                    ans=min(ans,1+rec(level+1,))
                }
            }
        */
        n=obstacles.size();
        memset(dp,-1,sizeof(dp));
        return (rec(0,2,obstacles));
    }
};