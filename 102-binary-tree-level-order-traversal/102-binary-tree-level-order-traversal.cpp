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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root){
            return {};
        }
        vector<TreeNode*> generation;
        generation.push_back(root);
        while(generation.size() > 0){
            // for(int i = 0; i < generation.size();++i){
            //     printf("%d,",generation[i]->val);
            // }
            // printf("\n");
            vector<TreeNode*> gen;
            vector<int> genNums;
            for(int i = 0; i < generation.size();++i){
                genNums.push_back(generation[i]->val);
                if(generation[i]->left){
                    gen.push_back(generation[i]->left);
                }
                if(generation[i]->right){
                    gen.push_back(generation[i]->right);
                }
            }
            ret.push_back(genNums);
            generation.clear();
            generation = gen;

        }
        return ret;
    }
};