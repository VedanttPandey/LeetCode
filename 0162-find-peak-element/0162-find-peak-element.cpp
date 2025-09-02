class Solution {
public:
    int findPeakElement(vector<int>& nums) {
       int n=nums.size();
       if(n==1)return 0;
       int l=0,r=n-1;
       while(l<r){
        int m=(l+r)>>1;
        if(nums[m]<nums[m+1]){
            l=m+1;
        }
        else r=m;
       }
       return l;
    }
};