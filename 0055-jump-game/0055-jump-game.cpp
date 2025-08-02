class Solution {
public:
    bool canJump(vector<int>& nums) {
        /*
            have to reach nth pos 
            currently at 1th pos
            each elmeent rep max jump power till that pos 
        */
        if(nums.size()==1)return true;
        int jumpP=0,maxR=0;
        for(int i=0;i<nums.size();++i){
           //max reach from this points
           maxR=max(i+nums[i],maxR);
           if(maxR>=(nums.size()-1))return true;
           if(nums[i]==0 && maxR==i)return false;
        }
        // cout << jumpP;
        return true;
    }
};