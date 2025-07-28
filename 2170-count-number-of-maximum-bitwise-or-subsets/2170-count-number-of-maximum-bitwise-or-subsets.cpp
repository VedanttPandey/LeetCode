class Solution {
public:
int subsets(vector<int> &a,int i,int cOR,int maxOR){
    if(i<0)return (cOR==maxOR)?1:0;
    return subsets(a,i-1,cOR,maxOR)+subsets(a,i-1,cOR | a[i],maxOR);
}
    int countMaxOrSubsets(vector<int>& nums) {
        /*
            to calculate max bitwise OR of a subset
                max bitwise OR will always be equal to max element of the array..??
                NO...
                max bitwise OR will always be greater than the max element if the element 
                of the arrays are different
                yes because the max bitwise OR should be at least of max element
                max bitwise OR will be the max of the whole array..??
                yes, the max biwtise of the array will be of the whole array as a single subset
        */
        /*
            Find number of subsets where OR(subset)==maxOR....
        */
        int maxOR=0;
        for(int num:nums){
            maxOR|=num;
        }
       return subsets(nums,nums.size()-1,0,maxOR);
        // return ans;
    }
};