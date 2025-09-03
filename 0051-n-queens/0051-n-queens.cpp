class Solution {
public:

vector<vector<string>> allP;
vector<string> currP;
int queens[10];

bool check(int row,int col){
    for(int i=0;i<row;++i){
        if(queens[i]==col || abs(col-queens[i])== abs (i-row))return false;
    }
    return true;
}

void rec(int level,int n){
    if(level==n){
        allP.push_back(currP);
        return;
    }

    for(int ch=0;ch<n;++ch){
        if(check(level,ch)){
            queens[level]=ch;
            currP[level][ch]='Q';
            rec(level+1,n);
            queens[level]=-1;
            currP[level][ch]='.';
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        memset(queens,-1,sizeof(queens));
         currP = vector<string>(n, string(n, '.'));
        rec(0,n);
       return allP;
    }
};