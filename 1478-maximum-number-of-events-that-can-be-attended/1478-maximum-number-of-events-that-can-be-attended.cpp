class Solution {
public:
    int maxEvents(vector<vector<int>>& e) {
        sort(e.begin(),e.end());
        priority_queue<int,vector<int>,greater<int>> pq;

        int ans=0;
        int cDay=0;
        int idx=0;
        while(!pq.empty() || idx<e.size()){
            if(pq.empty()){
                cDay=e[idx][0];
            }
            
            while(idx<e.size() && e[idx][0]<=cDay){
                pq.push(e[idx][1]);idx++;
            }
            pq.pop();
            ans++;
            cDay++;
            while(!pq.empty() &&  pq.top()<cDay){
                pq.pop();
            }
        }
        return ans;
    }
};