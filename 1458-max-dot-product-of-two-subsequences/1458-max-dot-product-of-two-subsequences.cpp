class Solution {
public:
int n,m;

int dp[501][501];
    int f(int i,int j,vector<int>& nums1, vector<int>& nums2){
        if(i==n || j==m)return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        int ans=INT_MIN;

        ans=max(ans,f(i+1,j+1,nums1,nums2)+nums1[i]*nums2[j]);

        ans=max(ans,f(i+1,j,nums1,nums2));
        ans=max(ans,f(i,j+1,nums1,nums2));

        return dp[i][j]=ans;
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        //dp[i][j] max dot product till ith index and jth index in array num1 & num2 starting from 0 

        /*
            if take both ith & jth element

            dp[i][j]= dp[i+1][j+1] + (nums1[i] * nums2[j])


            if we skip both dp[i][j]=max(dp[i][j],dp[i+1][j+1])


            if we take ith element


            if we take jth element
        */

        memset(dp,-1,sizeof(dp));

        n=nums1.size(),m=nums2.size();
        int maxi1=INT_MIN,maxi2=INT_MIN,mini1=INT_MAX,mini2=INT_MAX;
        for(int num : nums1){maxi1=max(maxi1,num);mini1=min(mini1,num);}
        for(int num : nums2){maxi2=max(maxi2,num);mini2=min(mini2,num);
}
        if(maxi1<0 && maxi2>=0 || maxi1>=0 && maxi2<0){
            return max({maxi1*mini2,maxi1*maxi2,mini1*maxi2,mini1*mini2});
        }
        return f(0,0,nums1,nums2);
    }
};