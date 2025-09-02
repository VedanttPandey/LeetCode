class Solution {
public:
//subaaray <=k - subarrays <=(k-1)
//number of distinct elements <= k 

int freq[20001];
int distinct=0;
int subarrays(vector<int>& nums,int k,int n){
    int tail=0,head=-1;
    int subarrayss=0;
    while(tail<n){
        while(head+1<n && distinct + (freq[nums[head+1]]==0 ? 1 : 0)<=k){
            head++;
            if(freq[nums[head]]==0){
                distinct++;
            }
            freq[nums[head]]++;
        }

        subarrayss+=(head-tail+1);

        if(tail<=head){
            freq[nums[tail]]--;
            if(freq[nums[tail]]==0)distinct--;
            tail++;
        }
        else{
            tail++;head=tail-1;
        }
    }
    return subarrayss;
}

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return (subarrays(nums,k,nums.size()) - subarrays(nums,k-1,nums.size()));
    }
};