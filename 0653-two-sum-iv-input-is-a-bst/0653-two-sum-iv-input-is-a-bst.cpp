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
/*class Solution {
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
};*/

class Solution {
public:

    stack<TreeNode*> asc;
    stack<TreeNode*> desc;

    TreeNode* getSmall(){
        if(asc.empty()){
            return NULL;
        }
        TreeNode* small = asc.top();
        asc.pop();
        TreeNode* rightChild = small->right;
        while(rightChild){
            asc.push(rightChild);
            rightChild = rightChild->left;
        }
        return small;
    }

    TreeNode* getBig(){
        if(desc.empty()){
            return NULL;
        }
        TreeNode* big = desc.top();
        desc.pop();
        TreeNode* leftChild = big->left;
        while(leftChild){
            desc.push(leftChild);
            leftChild = leftChild->right;
        }
        return big;
    }

    bool findTarget(TreeNode* root, int k) {
        if(root == NULL){
            return false;
        }
        TreeNode* node = root;
        while(node){
            asc.push(node);
            node = node -> left;
        }
        node = root;
        while(node){
            desc.push(node);
            node = node -> right;
        }
        TreeNode* small = getSmall();
        TreeNode* big = getBig();

        while(small->val <= big->val && small != big && (small && big) ){
            int sum = small->val + big->val;
            if( sum == k){
                return true;
            }
            else if(sum > k){
                big = getBig();
            }else{
                small = getSmall();
            }   
        }   
        return false; 
    }
};