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
    int num = 0;
    int ans = 0;
    int sumNumbers(TreeNode* root) {
        if(root == NULL){
            return ans;
        }
        num = num*10+root->val;
        if(root->left == NULL && root->right == NULL){
            ans +=num;
            num = num/10;
        }
        else{
            sumNumbers(root->left);
            sumNumbers(root->right);
            num = num/10;
        }
        return ans;
    }
};