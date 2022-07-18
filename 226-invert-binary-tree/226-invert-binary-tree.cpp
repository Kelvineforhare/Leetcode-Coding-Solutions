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
    TreeNode* invertTree(TreeNode* root) {
        vector<TreeNode*> queue;
        // if(!root){
        //     return root;
        // }
        queue.push_back(root);
        int i = 0;
        while(i < queue.size()){
            TreeNode* current = queue[i];
            if(!current){
                return root;
            }
            TreeNode* temp = current->left;
            current->left = current->right;
            current->right = temp;
            (current->left)? queue.push_back(current->left):void();
            (current->right)? queue.push_back(current->right):void();
            i++;
        }
        return root;
        
    }
};