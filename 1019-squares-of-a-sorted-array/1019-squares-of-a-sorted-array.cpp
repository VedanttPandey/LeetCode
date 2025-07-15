class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> pos(nums.size(),-1);
        int idx=nums.size()-1;
        int l=0,r=nums.size()-1;

        while(l<=r && idx>=0){
            if(abs(nums[l])<abs(nums[r])){
                pos[idx]=nums[r]*nums[r];
                r--;
            }
            else {
                pos[idx]=nums[l]*nums[l];
                l++;
            }
            idx--;
        }
        return pos;
    }
};