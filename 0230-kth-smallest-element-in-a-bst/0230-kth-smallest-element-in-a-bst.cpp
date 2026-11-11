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

    stack<TreeNode*> st;

    int getAns(){
        TreeNode* small = st.top();
        st.pop();
        TreeNode* rightChild = small -> right;
        while(rightChild){
            st.push(rightChild);
            rightChild = rightChild -> left;
        }
        return small->val;
    }

    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL){
            return NULL;
        }
        TreeNode* node = root;
        while(node){
            st.push(node);
            node = node ->left;
        }
        int ans = NULL;
        while( k > 0){
            ans = getAns();
            k--;
        }
        return ans;
    }
};