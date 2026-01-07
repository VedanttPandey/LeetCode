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

long long ans,total;
int mod=1e9+7;
void dfs1(TreeNode* root){
    total+=(root ? root->val : 0) ;

    if(root->left)dfs1(root->left);
    if(root->right)dfs1(root->right);
}
long long dfs2(TreeNode* root){
    if(!root)return 0;

    long long sum=root->val + dfs2(root->left) + dfs2(root->right);

    ans=max(ans,(total - sum)*sum);
    // ans%=mod;
    return sum;
}
    int maxProduct(TreeNode* root) {
        /*
                21
            11       9
        4       5   6
        */

        dfs1(root);

        dfs2(root);

        return ans%mod;
    }
};