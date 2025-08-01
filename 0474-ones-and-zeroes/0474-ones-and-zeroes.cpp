class Solution {
public:
int countZ(string s){
    int cnt=0;
    for(auto &i:s)cnt+=(i=='0' ? 1:0);
    return cnt;
}
int countO(string s){
    int cnt=0;
    for(auto &i:s)cnt+=(i=='1' ? 1:0);
    return cnt;
}
    int findMaxForm(vector<string>& strs, int m, int n) {
        /*
            at most mZEROES and nONES
            for a paticular string in str we have a choice of whether we can take it or not
            DP....???
        */
        /*
            lets say m=3 and m=2
            the max susbet wil be in dp[m][n]
        */
        /*
            for a partciular string i have got 
            number of zeroes and ones
        */
        vector<vector<int>> dp(m+1,vector<int> (n+1,0));
        dp[0][0]=0;

        for(auto &i:strs){
            int zero=countZ(i),one=countO(i);
            for(int j=m;j>=0;--j){//j represent the jth number of zeores that 
            //can be present in the current state
                for(int k=n;k>=0;--k){
                    //k represent the the curr numbr of zeroes in that partcilar states
                    //dp[j][k]-->reperestn max number of zeroes and ones that can present 
                    //in the current state of dp
                    /*
                        for a string to be a validate candidate both my number of zeroes
                        and ones should be less that current stat
                    */
                    if(zero<=j && one<=k){
                        dp[j][k]=max(dp[j][k],dp[j-zero][k-one]+1);
                    }
                }
            }
        }
        return dp[m][n];
    }
};