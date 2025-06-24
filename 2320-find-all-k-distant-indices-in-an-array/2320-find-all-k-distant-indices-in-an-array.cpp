class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        
        vector<int> curr;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==key)curr.push_back(i);
        }
        set<int> s;
        for(int i=0;i<curr.size();++i){
            int l=curr[i];
            int r=curr[i];
            while(l>=0  && (curr[i]-l)<=k){
                s.insert(l);
                l--;
            }
            while( r<nums.size() &&  abs(curr[i]-r)<=k){
                s.insert(r);
                r++;
            }
        }
        vector<int> a(s.begin(),s.end());
        return a;
    }
};