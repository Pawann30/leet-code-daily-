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
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> solve(TreeNode* root, int sum, int targetSum ){
        if(root == NULL){
            return ans;
        }
        sum +=root->val;
        path.push_back(root->val);
        if( root -> left == NULL && root->right == NULL){
            if(sum == targetSum){
                ans.push_back(path);
            }
            path.pop_back();
        } 
        else{
            solve(root->left , sum , targetSum);
            solve(root->right , sum ,targetSum);
            path.pop_back();
        }
        return ans;

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        return solve( root ,0, targetSum);
    }
};