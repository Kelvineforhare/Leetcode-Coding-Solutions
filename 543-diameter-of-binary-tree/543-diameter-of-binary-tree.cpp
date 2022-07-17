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
    int diameterOfBinaryTree(TreeNode* root){
        return solve(root,0);
    }
    
    int max(TreeNode* node){
        if(!node){
            return 0;
        }
        if(!node->left && !node->right){
            return 1;
        }
        TreeNode* right = node->right;
        TreeNode* left = node->left;
        int num = max(right);
        int num2 = max(left);
        return (num>num2)? 1+num:1+num2;
    } 
    
    int solve(TreeNode* node,int num){
        if(!node){
            return num;
        }
        if(!node->left && !node->right){
            return num;
        }
        TreeNode* r = node->right;
        TreeNode* l = node->left;
        int left = max(r);
        int right = max(l);
        if(left+right > num){
            num = left + right;
        }
        
        int nr = solve(r,num);
        int nl = solve(l,num);
        return (nr > nl)? nr:nl;
    }
};