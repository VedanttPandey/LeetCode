class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        int lE=*s.rbegin();
        if(s.size()==1 || lE<0){
            return lE;
        }
        else{
            int sum=0;
            for(auto &i:s){
                sum += (i>0 ? i : 0);
            }
            return sum;
        }
    }
};