class FindSumPairs {
public:
map<int,int> mp;
vector<int> a,b;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        a=nums1,b=nums2;
        for(auto &i:b)mp[i]++;
    }
    
    void add(int index, int val) {
        mp[b[index]]--;
        b[index]+=val;
        mp[b[index]]++;
    }
    
    int count(int tot) {
        int c=0;
        for(auto &i:a){
            c+=mp[tot-i];
        }
        return c;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */