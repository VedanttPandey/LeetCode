#define ll long long
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        /*
            c[i] of gas to travel from ith to (i+1)th station
            we have emoty tank at the start of the journey

            only a unique answer exists 
        */
        /*
            brute force-->
                    start from every gas station and keep adding the gas available
                    and when moving from ith sta to (i+1)th station
                        subtratct its cost from the total gas
                        at any point our sum gets<=0 then we cannot start from that index
        */

        /*
            lets say ith gas station is my answer 
            if(my sum) gets <=0 this can only happen when
                either 
                    1->we have traveled once in clock,, direction and is at ith index
                    2-> our sum doesnt get <= 0  
        */  

        /*
            we cannot start from an index where cost[i]>gas[i]

            so lets say we get 4 indexes where 
                we can start (cost[i]<=gas[i])
            but the gas station will be unique as the qus says
                so we can only have 1 gas station now which is the best startion
                out of those 4 
        */
        /*
            4-1=3
            3+5=8
            8-2=6
            6+1=7
            7-3=4
            4+2=6
            6-4=2
            2+3=5
            5-5=0
            0+4=4
        */

        int gasInFavour=0;
        int gasNotInFavour=0;
        int bestIdx=0;
        int cGas=0;
        for(int i=0;i<gas.size();++i){
            gasInFavour+=gas[i];
            gasNotInFavour+=cost[i];

            cGas+=(gas[i]-cost[i]);
            if(cGas<0){
                bestIdx=(i+1);
                cGas=0;
            }
        }
        return (gasInFavour>=gasNotInFavour ? bestIdx : -1 );
    }
};