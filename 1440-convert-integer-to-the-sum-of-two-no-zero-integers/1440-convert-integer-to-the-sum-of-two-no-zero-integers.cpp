class Solution {
public:
bool isNonZero(int n){
    while(n){
        if(n%10==0)return false;
        n/=10;
    }
    return true;
}
    vector<int> getNoZeroIntegers(int n) {
        int sum=0;
        int temp=n;
        temp--;
        int cnt=1;
        while(temp){
            if(isNonZero(temp) && isNonZero(cnt) && (temp+cnt==n)){
                return {temp,cnt};
            }
            cnt++;
            temp--;
        }
        return {-1,-1};
    }
};