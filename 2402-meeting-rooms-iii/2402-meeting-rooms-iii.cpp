class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        /*
            lets say we r at meeting m 

            so how many conditions 

            we have all rooms to iterate

            if(any room is free we put this to that)

            if all rooms are not free

            so there will be any meeting which endT < startT of the new meeting wo we put this to that
        */
        vector<long long> ans(n),rooms(n,-1);

        sort(meetings.begin(),meetings.end());

        for(auto &meet  : meetings){
            long long sT=meet[0],eT=meet[1];
            bool placed=false;
            long long meetRoom=-1,endTime=LLONG_MAX;
            for (int i = 0; i < n; ++i) {
                if (rooms[i] != -1 && rooms[i] <= sT)
                    rooms[i] = -1;
            }
            for(int i=0;i<n;++i){
                if(rooms[i]==-1){
                    rooms[i]=eT;
                    ans[i]+=1;
                    placed=true;
                    break;
                }
                else{
                    // we already have a meeting going here so what can we do 
                    if(rooms[i]<endTime){
                        endTime=rooms[i];
                        meetRoom=i;
                    }
                }
            }

            // now all the rooms are busy nd we have the earliest time of the room which will be free and 
            // availabel to use 

            //buffer
            if(!placed){
            long long buffer=endTime-sT;
            eT+=buffer;
            rooms[meetRoom]=eT;
            ans[meetRoom]+=1;
            }
        }

        long long room=0,maxi=0;

        for(int i=0;i<n;++i){
            if(ans[i]>maxi){
                maxi=ans[i];
                room=i;
            }
        }
        return room;
    }
};