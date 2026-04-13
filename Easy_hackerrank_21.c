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
 

void num_arr(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) return;

    num_arr(root->left, result, index);

    result[(*index)] = root->val;
    (*index)++;

    num_arr(root->right, result, index);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int* result = (int*)malloc(sizeof(int) * 100);
    int index = 0;

    num_arr(root, result, &index);

    *returnSize = index;
    return result;
}
