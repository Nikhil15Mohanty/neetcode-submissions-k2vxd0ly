class Solution {
public:
    
    bool isValid(TreeNode* root, long minValue, long maxValue) {

        // Empty tree is a valid BST
        if (root == nullptr) {
            return true;
        }

        // Current node must be inside the allowed range
        if (root->val <= minValue || root->val >= maxValue) {
            return false;
        }

        // Left subtree:
        // values must be between minValue and root->val
        if (!isValid(root->left, minValue, root->val)) {
            return false;
        }

        // Right subtree:
        // values must be between root->val and maxValue
        if (!isValid(root->right, root->val, maxValue)) {
            return false;
        }

        return true;
    }

    bool isValidBST(TreeNode* root) {
        return isValid(root, LONG_MIN, LONG_MAX);
    }
};