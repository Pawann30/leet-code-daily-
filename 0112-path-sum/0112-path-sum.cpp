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

    bool solve(TreeNode* root , int sum , int targetSum){
        TreeNode* node = root;
        if(node == NULL){
            return false;
        }
        sum +=node->val;
        if( node->left == NULL && node->right == NULL){
            if(sum == targetSum){
                return true;
            }
        }
        return solve(node->left,sum , targetSum) || solve(node->right, sum , targetSum);
    
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return false;
        }
        int sum = 0;
        return solve(root , sum ,targetSum);  
    }
};