class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        /*
            Avg pass ratio = sum of pass ration of all the classes / the number of classes

            pass ratio = numb of students that will pass the exam / total student of the class

            we want to maximise the avg pass ratio 
        */

        /*
            a/b to get max pass ration a+1/b+1 all differ 
                so heap to check the max 

            return {
                a+1/b+1 --> max value

                maybe maxDiff btwn a+1/b+1,a/b will work ,,yesssssss
            }
        */

        auto  diff=[&](int a,int b){
            return (double)(a+1)/(b+1)-(double)a/b;
        };
        priority_queue<tuple<double,int,int>> pq;
        for(auto & i: classes){
            pq.push({diff(i[0],i[1]),i[0],i[1]});
        }

        double ans=0.0;

        while(extraStudents--){
            auto [x,y,z]=pq.top();
            pq.pop();
            y++;z++;
            pq.push({diff(y,z),y,z});    
        }

        while(!pq.empty()){
            auto [l,c,d]=pq.top();
            pq.pop();
            ans+=(double)c/d;
        }

        return (ans/classes.size());
    }
};