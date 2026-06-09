class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n=nums.size();
        long long a=*max_element(nums.begin(),nums.end());
        long long b=*min_element(nums.begin(),nums.end());
        long long c=a-b;
        long long ans = c*k;
        return ans;
    }
};