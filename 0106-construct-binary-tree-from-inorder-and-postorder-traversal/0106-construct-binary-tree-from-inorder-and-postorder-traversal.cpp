class Solution {
public:
    map<int, int> mp; 

    TreeNode* helper(vector<int> &inorder, int inStart, int inEnd,
                     vector<int> &postorder, int postStart, int postEnd) {
        if (inStart > inEnd || postStart > postEnd) return NULL;

        TreeNode* root = new TreeNode(postorder[postEnd]);
        int idxRoot = mp[root->val];
        int leftSize = idxRoot - inStart;

        root->left=helper(inorder,inStart,idxRoot-1,postorder,postStart,postStart+leftSize-1);
        root->right=helper(inorder,idxRoot+1,inEnd,postorder,postStart+leftSize,postEnd-1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }
        return helper(inorder, 0, n - 1, postorder, 0, n - 1);
    }
};
