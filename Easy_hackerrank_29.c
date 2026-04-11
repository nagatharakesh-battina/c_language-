/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


void helper(struct TreeNode* root, int* result, int* index) {
    if (root == NULL)
        return;

    helper(root->left, result, index);
    helper(root->right, result, index);

    result[*index] = root->val;
    (*index)++;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(1000 * sizeof(int)); // max nodes <= 1000
    int index = 0;

    helper(root, result, &index);

    *returnSize = index;
    return result;
}
