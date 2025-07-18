class Solution {
public:
    int longestMountain(vector<int>& a) {
        int maxS=0;

        // int l=0,r=1;
        int n=a.size();
        for(int i=1;i<n-1;i++){
            if(a[i-1]<a[i] && a[i]>a[i+1]){
                //peak found now check max range
                int l=i,r=i+1;

                while(l>0 && a[l]>a[l-1]){
                    l--;
                }
                while(r<n-1 && a[r]>a[r+1]){
                    r++;
                }

                maxS=max(maxS,(r-l+1));
            }
        }
        return maxS;
    }
};

/*
    
      3
    2   4
  1       5
*/

/*
    a[i-1]<a[i]>a[i+1]<a[i+2]<a[i+3]>a[i+4]               
*/