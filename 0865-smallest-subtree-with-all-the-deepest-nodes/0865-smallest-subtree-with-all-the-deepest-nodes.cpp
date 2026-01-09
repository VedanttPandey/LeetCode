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
int maxi=0;
TreeNode* lca=NULL;
int  ans(TreeNode* root,int depth){
    maxi=max(maxi,depth);
    if(!root)return depth;

    int lefti= ans(root->left,depth+1);
    int righti= ans(root->right,depth+1);

    if(lefti==maxi && righti==maxi)lca=root;

    return max(lefti,righti);
}
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        /*
            find lca of all nodes present at last level

            find all nodes present at last level 

            {current node , the nodes at its depts , their lca }

            {root} - > {left depth , lca }
        */
        ans(root,0);
        return lca;
    }
};