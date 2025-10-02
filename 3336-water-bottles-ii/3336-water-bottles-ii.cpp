class Solution {
public:
    int maxBottlesDrunk(int b, int e) {
        int ans=b;
        while(b>=e){
            ans++;
            b-=e-1;
            e++;
        }
        return ans;
    } 
};