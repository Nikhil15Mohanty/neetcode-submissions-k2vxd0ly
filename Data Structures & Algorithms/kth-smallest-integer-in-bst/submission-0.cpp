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
    int kthSmallest(TreeNode* root, int k) {
        queue<TreeNode*> que;
        que.push(root);
        vector<int> result;
        int answer;
        while(!que.empty()){
            int level = que.size();
            while(level--) {
                TreeNode* node = que.front();
                que.pop();
                result.push_back(node->val);

                if (node->left!=NULL) que.push(node->left);
                if (node->right!=NULL) que.push(node->right);
            }
        }
        sort(result.begin(), result.end());
        for (auto arr: result) {
            cout<<arr<<" ";
        }
        return result[k-1];
    }
};
