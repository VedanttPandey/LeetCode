class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum=0;
        for(int num : nums){
            vector<int> curr;
            for(int i=1;i*i<=num ; ++i){
                if(num%i==0){
                    curr.push_back(i);
                    if(i!=num/i)curr.push_back(num/i);
                }
                if(curr.size()>4)break;
            }
            if(curr.size()==4)sum+=accumulate(curr.begin(),curr.end(),0ll);
        }
        return sum;
    }
};