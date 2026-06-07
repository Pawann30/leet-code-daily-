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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int , TreeNode*> mp;
        unordered_set<int> childs;
        for(vector<int>& vec :  descriptions){
            int par = vec[0];
            int child = vec[1];
            int left = vec[2];

            if(mp.find(par) == mp.end() ){
                mp[par] = new TreeNode(par);
            }

            if(mp.find(child) == mp.end() ){
                mp[child] = new TreeNode(child);
            }
            if(left == 1){
                mp[par]->left = mp[child];
            }else{
                mp[par]->right = mp[child];
            }
            childs.insert(child);
        }

        for(vector<int>& vec :  descriptions){
            int parent =vec[0];
            if(childs.find(parent) == childs.end()){
                return mp[parent];
            }
        }
        return NULL;
    }
};