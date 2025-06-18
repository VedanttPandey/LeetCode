class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=0;
        int ok=1;
        int newSet=0;
        vector<vector<int>> a((nums.size()/3),vector<int> ());
        a[newSet].push_back(nums[0]);
        for(int r=1;r<nums.size();++r){
            if(newSet==(nums.size()/3) && r!=nums.size()-1){
                ok=0;break;
            }
            if(a[newSet].size()==3){
                newSet++;
                if (newSet >= nums.size() / 3) {
                    ok = 0;
                    break;
                }
                a[newSet].push_back(nums[r]);
                l=r;
            }
            else {
                if(abs(nums[l]-nums[r])<=k){
                    a[newSet].push_back(nums[r]);
                }
                else{
                    ok=0;break;
                }
            }
        }
        if(!ok)a.clear();
        return a;
    }
};