class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        /*
            num1- x*(2^i + num2)
                num1 -x*num2 - x*(2^i)
            
            30-60 steps max
        */

        for(int i=1;i<=60;++i){
            long long curr=1LL*num1-1LL*i*num2;
            if(curr<i)return -1;
            if(i>=__builtin_popcountll(curr))return i;   
        }
        return -1;
    }
};