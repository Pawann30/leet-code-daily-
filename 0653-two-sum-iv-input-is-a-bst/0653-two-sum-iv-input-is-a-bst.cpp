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
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        stack<TreeNode*> st;
        TreeNode* node = root;
        while(true){
            if(node != NULL){
                st.push(node);
                node = node->left;
            }
            else{
                if(st.empty() == true){
                    break;
                }else{
                    node = st.top();
                    st.pop();
                    v.push_back(node->val);
                    node = node->right;
                }
            }
        }
        int n = v.size();
        int i = 0 , j = n-1;
        while(i<j){
            int sum = v[i]+v[j];
            if(sum == k){
                return true;
            }else if(sum > k){
                j--;
            }else{
                i++;
            }
        }
        return false;
    }
};