#define ll long long
class Solution {
public:


bool isP(vector<int>& time, ll mid,ll totalTrips){
    ll curr=0;
    for(auto &i:time){
        if(i<=mid)curr+=(mid/i);
    }
    return (curr>=totalTrips);
}
ll bs(vector<int>& time, int totalTrips,ll l,ll r){
    ll ans=r;
    while(l<=r){
        ll m=(l+r)>>1;
        if(isP(time,m,totalTrips)){
            ans=m;
            r=m-1;
        }
        else l=m+1;
    }
    return ans;
}
    long long minimumTime(vector<int>& time, int totalTrips) {
        // ll r=time[0](ll)*totalTrips;
        return bs(time,totalTrips,1,1e14);
    }
};