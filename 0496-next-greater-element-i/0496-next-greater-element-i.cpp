class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        stack<int> st;
        vector<int> ans;
        for(int i  =0 ;i<n; i++){
            st.push(nums1[i]);
        }
        int i = 0;
        while(!st.empty()){
            if(nums2[i]==st.top()){
                st.pop();
                bool found = false;
                for(int j = i + 1; j < m; j++){
                    if(nums2[j] > nums2[i]){
                        ans.push_back(nums2[j]);
                        found = true;
                        break;
                    }
                }
                if(!found){
                    ans.push_back(-1);
                }
                i = 0;
            }else{
                i++;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};