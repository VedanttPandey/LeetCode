class NumArray {
public:
vector<int> psum;
    NumArray(vector<int>& nums) {
        psum.resize(nums.size(),0);
        psum[0]=nums[0];
        for(int i=1;i<nums.size();++i){
            psum[i]=psum[i-1]+nums[i];
        }
    }
    
    int sumRange(int left, int right) {
    //     for(auto &i:psum){
    //     cout<<i<< " "<< "\n";
    //     }
    // cout << left << " " << right;
        return (left == 0 ? psum[right] : psum[right]-psum[left-1]); 
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */