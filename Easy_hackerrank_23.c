/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 bool isMirror(struct TreeNode* l,struct TreeNode* r){
    if(l==NULL && r==NULL){
        return true;
    }
    if(l==NULL || r==NULL){
        return false;
    }
    if(l->val!=r->val){
        return false;
    }
    return isMirror(l->left,r->right ) && isMirror(l->right,r->left );
 }
bool isSymmetric(struct TreeNode* root) {
    
    if(root==NULL){
        return true;
    }
    return isMirror(root->left,root->right); 
    
}
