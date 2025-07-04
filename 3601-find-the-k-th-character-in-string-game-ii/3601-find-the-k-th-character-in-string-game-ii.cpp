#define ll long long
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        //Number of operations doesnt matter
        /*
            just have to find the kth pos 
            so will use only that much till till my len<k
            and len*=2 in every operation
        */

        vector<ll> length;
    long long clen=1;
        int i=0;
        while(i<operations.size()){
            clen*=2;
            length.push_back(clen);
            
            if(clen>=k)break;
            i++;
        }
        int op=0;
        for(int i=length.size()-1;i>=0;--i){
            ll len=length[i];
            len/=2;
            if(k>len){//right side
                if(operations[i])op++;
                k-=len;
            }
        }
        return (char)((('a' - 'a' + op) % 26) + 'a');
    }
};
