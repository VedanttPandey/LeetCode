/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
TreeNode* func(vector<int> &nums,int l,int r){
        if(l>r){//base condtion to stop recursions
            return nullptr;//ENDING OF OUR TREE
        }

        int mid=(l+r)>>1;//(mid , left ,right)

        /*
            1 2 3 4 5
            mid->2(inddex)
            l=0,r=5
        */
        TreeNode* node=new TreeNode(nums[mid]);//buildeing root node with root as mid element in the nums array
        node->left=func(nums,l,mid-1);
        node->right=func(nums,mid+1,r);

        /*
            3 will be made as root and now for left we recurisvely call again func so that
            now my operations will be performed for 1,2
            and for right (4,5)

            tree after first iteration
                    3

            tree after second iteration

                3
            2       

            tree after third iteration

                    3
                2       4
            
            tree after fourht iteration

                    3
                2        4
            1       

            tree after 5th iteration
                    3
                2       4
            1                 5


        */

        return node;
}
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        //-->>OBSERVATIONS
        /*
            1->Height balance --->> depth same (depth of any 2 subtrees always <=1)
            Now , how to get all at same level
                best ans is mid 
                becase 
                    1 2 3 4 5
                        if we take 3 as mid then(1,2) at left and (4,5) at right
                        this means height diff is 0
                            3
                        2       4
                    1               5
                        
                    1 2 3 4 5 6

                    (3 or 4 can take any doesnt matter)
                        3
                    2       4
                1         6      5

                balance height
        */

        /*
            Implementation 
                just take mid 
                    and left and right subtree (do recursivel till we reach the end)
                    or (right>left)
        */

        return func(nums,0,nums.size()-1);
    }
};