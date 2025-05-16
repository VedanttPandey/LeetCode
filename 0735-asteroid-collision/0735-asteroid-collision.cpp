class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> st;
        st.push(a[0]);
        for(int i=1;i<a.size();++i){
            int curr=a[i];
            int destroyed=false;
            int ok=1;
            while (!st.empty() && st.top() > 0 && curr < 0){//will collide
            int top=st.top();
            if(abs(top)>abs(curr)){//top will will win 
                // curr=top;
                destroyed=1;
                // st.pop(); 
                break;
            }
            else if(abs(top)<abs(curr)){//curr will win and will pop the stack if not empty else will push curr in the stack
                st.pop();
                continue;
            }
            else{//pop the stack 
                st.pop();
                destroyed=1;
                break;
            }
            }
            if(!destroyed)st.push(curr);
        }
         vector<int> ans(st.size());
        for (int i = st.size() - 1; i >= 0; --i) {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};