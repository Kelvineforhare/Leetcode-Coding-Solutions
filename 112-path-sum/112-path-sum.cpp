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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false;
        int new_sum = sum - root->val;
        if(!root->left && !root->right) return new_sum==0;
        return hasPathSum(root->left, new_sum) || hasPathSum(root->right, new_sum);
    }
    
    bool hasP(TreeNode* root, int targetSum,int curSum){
        if(!root){
            return false;
        }
        printf("root val: %d \n",root->val);
        if(!root->right && !root->left){
            if(curSum+root->val != targetSum){
                return false;
            }
            return true;
        }
        
        bool left = hasP(root->left,targetSum,curSum+root->val);
        if(left){
            return true;
        }
        bool right = hasP(root->right,targetSum,curSum+root->val);
        return right;
    }
};