/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
class Solution {
public:
    TreeNode* ans = NULL;
    int lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) {
            return 0;
        }
        int left = lca(root->left , p , q);
        int right = lca(root->right , p , q);
        int self = 0;
        if(root == p || root == q){
            self = 1;
        }
        int total = left + right + self;
        if(total == 2 && ans == NULL){
            ans = root;
        }
        return total;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans = NULL;
        lca(root, p, q);
        return ans;
    }
};*/

class Solution {
    public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL ){
            return NULL;
        }
        if(root->val == p->val || root->val == q->val){
            return root; 
        }
        else if(p->val > root->val && q->val > root->val){
            return lowestCommonAncestor(root->right , p ,q);
        }
        else if(p->val < root->val && q->val < root->val){
            return lowestCommonAncestor(root->left , p ,q);
        }
        return root;
    }
};

