class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        /*int n=nums.size();
        vector<long long> ans;
        stack<int> st;
        for(int x: nums){
            long long curr = x;
            while(!st.empty() && st.top() == curr){
                curr +=st.top();
                st.pop();
            }
            st.push(curr);
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;*/
        vector<long long> st;
        for (int x : nums) {
            st.push_back(x);

            while (st.size() >= 2) {
                long long a = st.back();
                st.pop_back();
                long long b = st.back();

                if (a == b) {
                    st.back() = a + b;
                } else {
                    st.push_back(a);
                    break;
                }
            }
        }

        return st;
    }
};