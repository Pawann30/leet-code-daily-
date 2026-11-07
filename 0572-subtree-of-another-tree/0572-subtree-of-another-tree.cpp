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
    bool ans(TreeNode* p , TreeNode* q){
       /* if(root1 != root2) return false;
        else{
            root1 = root1->left;
            root2 = root2->left;
        }*/
        if( p == NULL && q == NULL) return true;
        if( p == NULL || q == NULL) return false; 
        if( p->val != q->val) return false;
        return ans( p->left , q->left) && ans( p->right , q->right);
    }

    bool solve(TreeNode* root , TreeNode* subRoot){
        if(root == NULL ) return false;
        if(root->val == subRoot->val){
            if(ans(root,subRoot)){
                return true;
            }
        }
        return solve(root->left , subRoot) || solve(root->right , subRoot);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot == NULL && root == NULL ) return true;
        if(subRoot != NULL && root == NULL ) return false;
        return solve( root ,subRoot);
    }
};