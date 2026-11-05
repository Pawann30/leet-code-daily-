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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
        q.push(root);
        bool zigzag = false;
        while(!q.empty()){
            int l = q.size();
            vector<int> temp;
            for(int i=0; i < l; i++){
                TreeNode* a = q.front();
                q.pop();
                temp.push_back(a->val);
                
                if(a->left != NULL){
                    q.push(a->left);
                }
                if(a->right != NULL){
                    q.push(a->right);
                }    
            }
            if(zigzag){
                reverse(temp.begin(),temp.end());
            }
            ans.push_back(temp);
            zigzag = !zigzag;
        }
        return ans;
    }
};