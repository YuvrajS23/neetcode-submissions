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
    int preIndex = 0;
    unordered_map<int , int> indexLocator;

    TreeNode* dfs(vector<int>& preOrder, int l, int r) {
        if(l > r) return nullptr;
        int root = preOrder[preIndex];
        TreeNode* node = new TreeNode(root);
        preIndex++;
        int mid = indexLocator[root];
        node->left = dfs(preOrder, l, mid-1);
        node->right = dfs(preOrder, mid+1, r);
        return node;

    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++){
            indexLocator[inorder[i]] = i;
        }
        return dfs(preorder, 0, inorder.size() - 1);
    }
};
