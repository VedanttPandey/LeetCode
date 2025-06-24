class Solution {
public:

bool isP(int mid,vector<int> &a){
    int cnt=0;
    for(auto &i:a){
        if(i>=mid)cnt++;
    }

    return (cnt<=a.size() && cnt>=mid);
}
int bs(int l,int r,vector<int> &a){
    int ans=0;
    while(l<=r){
        int m=l+(r-l)/2;

        if(isP(m,a)){
            ans=max(ans,m);
            l=m+1;
        }
        else r=m-1;
    }
    return ans;
}
    int hIndex(vector<int>& h) {
        sort(h.begin(),h.end());
        return bs(0,h[h.size()-1],h);
    }
};