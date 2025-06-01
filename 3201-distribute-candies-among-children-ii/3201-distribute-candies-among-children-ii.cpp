class Solution {
public:
    long long distributeCandies(int n, int limit) {
        /*
            a+b+c<=n && (a,b,c)<=limit
            a+b<=(n-c)
            limit for a child is (limit)

            so,now i have given C some amount of candies now how ,much amout should i give to B and A..??
            leftCandies=(n-C)
            So,what if i find the number of ways of candies that i can give to C and suffle pos..?
            min amout of candies that i can gove to C is 0..?
            minamount should be limit..? 
            maxamount is limit && min amount is max(0,n-2*limit)
        */
        long long minA=max(0,n-2*limit),totalWays=0;
        int maxA=min(n,limit);
        for(int i=minA;i<=maxA;++i){
            totalWays+=(min(limit,n-i)-max((n-i-limit),0))+1;
        }
        return totalWays;
    }
};