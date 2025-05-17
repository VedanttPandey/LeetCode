class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start=0,end=nums.size()-1,m=0;
        while(start<=end && m<=end){
            if(nums[m]==0 && start!=m){swap(nums[m],nums[start++]);}
            else if(nums[m]==2 && m<end){swap(nums[m],nums[end--]);}
            else m++;
        }
    }
};