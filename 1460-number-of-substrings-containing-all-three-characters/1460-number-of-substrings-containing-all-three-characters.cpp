class Solution {
public:

bool check(map<char,int> &freq,char ch){
    if(ch=='a'){
        if(freq['b']<1 || freq['c']<1)return false;
    }
    else if(ch=='b'){
        if(freq['a']<1 || freq['c']<1)return false;
    }
    else if(ch=='c'){
        if(freq['a']<1 || freq['b']<1)return false;
    }
    return true;
}
    int numberOfSubstrings(string s) {
        int ans=0;

        int head=-1,tail=0;
        int n=s.size();
        map<char,int> freq;
        while(tail<n){
            while(head+1<n && !check(freq,s[head+1])){
                head++;
                freq[s[head]]++;
            }

            if(head+1<n){
                ans+=(n-1-head);
            }

            if(tail<=head){
                freq[s[tail]]--;
                tail++;
                // ans--;
            }
            else {
                tail++;
                head=tail-1;
            }
        }
        return ans;
    }
};