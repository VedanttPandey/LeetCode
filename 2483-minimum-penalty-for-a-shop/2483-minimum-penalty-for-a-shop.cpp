class Solution {
public:
    int bestClosingTime(string customers) {
        int maxP=0;
        int currP=0;
        int time=-1;
        for(int i=0;i<customers.size();++i){
            currP+=(customers[i]=='Y' ? 1 : -1);
            if(currP>maxP){
                time=i;
                maxP=currP;
            }
        }
        return time+1;
    }
};