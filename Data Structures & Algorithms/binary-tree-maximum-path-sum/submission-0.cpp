class Solution {
public:

    int answer = INT_MIN;

    int maxGain(TreeNode* root) {

        // Empty node contributes 0
        if (root == nullptr) {
            return 0;
        }

        // Maximum gain from left subtree
        int leftGain = maxGain(root->left);

        // Maximum gain from right subtree
        int rightGain = maxGain(root->right);

        // Ignore negative paths
        leftGain = max(0, leftGain);
        rightGain = max(0, rightGain);

        // Best path passing through current node
        int currentPath = root->val + leftGain + rightGain;

        // Update global answer
        answer = max(answer, currentPath);

        // Return only one side to parent
        return root->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {

        maxGain(root);

        return answer;
    }
};