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

    TreeNode* ans = NULL;
    unordered_set<TreeNode*> deepest;
    int LCA(TreeNode* root){
        if(root == NULL ){
            return 0;
        }
        TreeNode* node = root;
        int left =  LCA(node->left);
        int right = LCA(node->right);
        int self = deepest.count(root);
        
        int total = left + right + self;
        if(total == deepest.size() && ans == NULL) {
            ans = root;
        }
        return total;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root == NULL){
            return root;
        }
        //vector<TreeNode*> t;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int n = q.size();
            deepest.clear();

            for(int i =0;i<n ; i++){
                TreeNode*node = q.front();
                q.pop();
                deepest.insert(node);

                if(node->left != NULL){
                    q.push(node->left);
                }
                if(node->right != NULL){
                    q.push(node->right);
                }
            }
        }
        ans = NULL;
        LCA( root );  
        return ans;   
    }
};