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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        vector<TreeNode*> level;
        if(root){
            level.push_back(root);
            ans.push_back(root->val);
        }
        while(level.size() > 0){
            double avg = 0;
            double num = 0;
            vector<TreeNode*> newLevel;
            for(int i = 0; i < level.size();++i){
                if(level[i]->left){
                    ++num;
                    avg += level[i]->left->val;
                    newLevel.push_back(level[i]->left);
                    //cout << avg << " " << num << " " << "\n";
                }
                if(level[i]->right){
                    ++num;
                    avg += level[i]->right->val;
                    newLevel.push_back(level[i]->right);
                }
            }
            for(int i =0 ; i < level.size();++i){
                cout << level[i]->val << " , ";
            }
            cout << "\n";
            level.clear();
            level = newLevel;
            if(num > 0){
                avg = avg/num;
                ans.push_back(avg);
            }
        }
        return ans;
    }
};