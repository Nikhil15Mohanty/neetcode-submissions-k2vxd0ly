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
    int definiteRootValue = 0;
    unordered_map<int,int> inorderIndex;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i<inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }

        return bst(preorder, 0, inorder.size()-1);
    }

    TreeNode* bst(vector<int>& preorder, int start, int end) {
        if (start > end) return NULL;

        int rootValue = preorder[definiteRootValue++];

        TreeNode* root = new TreeNode(rootValue);

        int rootInInorderIndex = inorderIndex[rootValue];

        root -> left = bst(preorder, start, rootInInorderIndex-1);
        root -> right = bst(preorder, rootInInorderIndex+1, end);

        return root;
    }
};
