class Solution {
public:

bool found(map<char,int> &freqT,map<char,int> &freqS,char ch){
    for(auto &[l,r] : freqT){
       if(ch==l){
           if(freqS[ch]+1<r)return false;
       }
       else{
        if(freqS[l]<r)return false;
       }
    }
    return true;
}
    string minWindow(string s, string t) {
        map<char,int> freqT,freqS;
        for(auto &i:t){
            freqT[i]++;
        }
        int n=s.size();
        int head=-1,tail=0;
        int ans=n+1;
        int idx=-1;
        while(tail<n){
            while(head+1<n && !found(freqT,freqS,s[head+1])){
                head++;
                freqS[s[head]]++;
            }
            if(head+1<n){
                // ans=min(ans,head-tail+2);
                // idx=tail;
                if(head-tail+2<ans){
                    ans=head-tail+2;
                    idx=tail;
                }
            }

            if(tail<=head){
                freqS[s[tail]]--;
                tail++;
            }
            else {
                tail++;
                head=tail-1;
            }
        }
        return (ans==n+1 ? "" : s.substr(idx,ans));
    }
};