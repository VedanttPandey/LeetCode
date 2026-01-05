class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0,cd=0;

        for(int num : nums){
            cd= (cnt ==0 ? num : cd);

            cnt +=(num==cd ? 1 : -1);
        }

        return cd;
    }
};