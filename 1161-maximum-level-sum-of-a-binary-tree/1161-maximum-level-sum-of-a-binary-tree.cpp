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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;

        int maxSum=INT_MIN,maxL=INT_MIN;

        q.push(root);

        int level=1;

        while(!q.empty()){
            int size=q.size();
            int cSum=0;
            vector<TreeNode*> v;
            for(int i=0;i<size;++i){
                TreeNode* node= q.front();
                v.push_back(q.front());
                q.pop();
                cSum+=node->val;
                
            }

            if(cSum>maxSum){
                maxSum=cSum;
                maxL=level;
            }
            level+=1;

            for(auto node : v){
                // TreeNode* node= v[i];
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
        }
        return maxL;
    }
};