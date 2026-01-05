class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        /*
            if both neg then we get max sum else sum remains same 
        */

        long long cntN=0,minE=1e9;

        long long sum=0;

        for(int i=0;i<matrix.size();++i){
            for(int j=0;j<matrix[0].size();++j){
                sum+=abs(matrix[i][j]);
                cntN+=(matrix[i][j]<0 ? 1 : 0);
                minE=min(minE,1LL*abs(matrix[i][j]));
            }
            // cout << sum << '\n';
        }
        // cout << sum << ' ' << cntN << ' '<< minE;
        return (cntN & 1 ? sum-2*minE : sum);

    }
};