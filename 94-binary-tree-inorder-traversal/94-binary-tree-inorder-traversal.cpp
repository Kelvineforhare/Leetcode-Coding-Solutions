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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> arr;
        return inorderAns(root,arr);
    }
    
    vector<int> inorderAns(TreeNode* root,vector<int>& arr){
        if(!root){
            return arr;
        }
        
        
        inorderAns(root->left,arr);
        arr.push_back(root->val);
        inorderAns(root->right,arr);
        
        return arr;
    }
    
};