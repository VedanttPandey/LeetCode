class Solution {
public:
    int minMaxDifference(int num) {
        string forMax;
        string nums=to_string(num);
        char toMx=' ';
        char toMn=' ';
        for(auto &i:nums){
            if(i!='9'){
                toMx=i;break;
            }
        }
        for(auto &i:nums){
            if(i!='0'){
                toMn=i;break;
            }
        }
        string forMin;
        for(auto &i:nums){
            if(i==toMx){forMax+='9';}
            else {forMax+=i;}
        }
        for(auto &i:nums){
            if(i==toMn){forMin+='0';}
            else {forMin+=i;}
        }
        cout<<forMax<<" "<<forMin<<" ";
        cout<<toMx<<" "<<toMn;
        int n1=stoi(forMax),n2=stoi(forMin);
        return (n1-n2);
    }
};