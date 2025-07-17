class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int top=0,left=0,bottom=n-1,right=m-1;
        vector<int> ans;
        while(top<=bottom && left <= right){
            //top row 
            for(int i=left;i<=right;++i){
                ans.push_back(matrix[top][i]);
            }
            top++;
            //right col
            for(int i=top;i<=bottom;++i){
                ans.push_back(matrix[i][right]);
            }
            right--;
            //bottom row
            for(int i=right;i>=left;--i){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
            //left col
            for(int i=bottom;i>=top;--i){
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
        if(ans.size()>(m*n)){
            while(ans.size()>(m*n))ans.pop_back();
        }
        return ans;
    }
};