class Solution {
public:
    map<int,int> mp; // value -> inorder index

    TreeNode* build(vector<int> &pre, vector<int> &in, 
                    int preSidx, int preEidx, 
                    int inSidx, int inEidx) {
        if (preSidx > preEidx || inSidx > inEidx) return nullptr;

        TreeNode* root = new TreeNode(pre[preSidx]);
        int rootIdx = mp[root->val];
        int leftSize = rootIdx - inSidx;

        root->left = build(pre, in, preSidx + 1, preSidx + leftSize, inSidx, rootIdx - 1);
        root->right = build(pre, in, preSidx + leftSize + 1, preEidx, rootIdx + 1, inEidx);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // mp.clear();
        for (int i = 0; i < inorder.size(); ++i) {
            mp[inorder[i]] = i;
        }
        return build(preorder, inorder, 0, (int)preorder.size() - 1, 0, (int)inorder.size() - 1);
    }
};
