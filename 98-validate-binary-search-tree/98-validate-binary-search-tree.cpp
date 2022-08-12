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
    bool isValidBST(TreeNode* root) {
        if(!root){
            return true;
        }
        if(root->right && !isValidBST(root->right)){
            return false;
        }
        if(root->left && !isValidBST(root->left)){
            return false;
        }
        return isValidRight(root, root->right) && isValidLeft(root,root->left);
        
    }
    
    bool isValidRight(TreeNode* root, TreeNode* right){
        if(right){
            printf("root val : %d right val : %d \n",root->val,right->val);
        }
        
        if(!right){
            return true;
        }
        else if(root->val >= right->val){
            
            return false;
        }
        return isValidRight(root, right->left) && isValidRight(root,right->right);
    }
    
    bool isValidLeft(TreeNode* root, TreeNode* left){
        if(!left){
            return true;
        }
        else if(root->val <= left->val){
            return false;
        }
        return isValidLeft(root, left->left) && isValidLeft(root,left->right);
    }
};