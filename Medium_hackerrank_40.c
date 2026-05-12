/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int calculateSum(struct TreeNode* node, int currentSum) {
    if (node == NULL) {
        return 0;
    }

    currentSum = currentSum * 10 + node->val;

    if (node->left == NULL && node->right == NULL) {
        return currentSum;
    }

    return calculateSum(node->left, currentSum) + 
           calculateSum(node->right, currentSum);
}

int sumNumbers(struct TreeNode* root) {
    return calculateSum(root, 0);
}
