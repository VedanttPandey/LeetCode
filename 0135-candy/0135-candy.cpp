class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(),1);
        // fill(candies.begin(),candies.end(),1);
        for(auto &i:candies)cout<<i<<" ";
        for(int i=1;i<ratings.size();++i){
            if(ratings[i]>ratings[i-1]){
                if(candies[i]==candies[i-1])candies[i]+=1;
                else if(candies[i]<candies[i-1])candies[i]=candies[i-1]+1;
            }
            // else if(ratings[i]==ratings[i-1] && candies[i]<candies[i-1])candies[i]=candies[i-1];
        }
        for(int i=ratings.size()-2;i>=0;--i){
            if(ratings[i]>ratings[i+1]){
                if(candies[i]==candies[i+1])candies[i]+=1;
                else if(candies[i]<candies[i+1])candies[i]=candies[i+1]+1;
            }
            // else if(ratings[i]==ratings[i+1] && candies[i]<candies[i+1])candies[i]=candies[i+1];
        }
        for(auto &i:candies)cout<<i<<" ";
        return accumulate(candies.begin(),candies.end(),0ll);
    }
};