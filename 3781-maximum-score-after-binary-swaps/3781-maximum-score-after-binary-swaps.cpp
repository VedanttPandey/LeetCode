class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        //maximise the score
        //score  is the place adding up where s[i] is 1

        priority_queue<int> pq;

        long long ans=0;
        int i=0;
        for(int num : nums){
            pq.push(num);
            if(s[i]=='1'){
                ans+=(pq.top());
                pq.pop();
            }
            i++;
        }
        return ans;
    }
};