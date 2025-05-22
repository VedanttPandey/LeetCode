class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(),queries.end());
        //best querie is the one that willl affect my current Idx and will have farthest point because it will cover many indexes
        priority_queue<int> maxH;
        int j=0,psum=0,used=0;
        vector<int> diffA(nums.size()+1);
        for(int i=0;i<nums.size();++i){
            while(j<queries.size() && queries[j][0]<=i){
                maxH.push(queries[j][1]);
                j++;
            }
            //Now i have got all queries that will affect my current idx and will cover most of the indexes
            while(nums[i]>(psum+diffA[i])){
                if(maxH.empty()){
                    return -1;
                }
                int top=maxH.top();
                maxH.pop();
                if(top>=i){
                diffA[i]++;
                diffA[top+1]--;
                used++;
                }
            }
            psum+=diffA[i];
        }
        return (queries.size()-used);
    }
};