class Solution {
public:
    string answerString(string word, int numFriends) {
        /*
            every round diff split,, so maybe we can check for each index the max lex larg 
            string poss..?
        */

        // char c='\0';
        // for(char charr:word){
        //     c=max(c,charr)
        // }
        // if(word.size()==numFriends){
        //     return c;
        // }
        if(numFriends==1){
            return word;
        }
        string ans="";
        for(int i=0;i<word.size();++i){
            ans=max(ans,word.substr(i,word.size()-numFriends+1));
        }
        return ans;
    }
};