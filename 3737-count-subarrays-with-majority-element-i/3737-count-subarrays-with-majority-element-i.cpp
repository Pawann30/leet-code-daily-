class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
         int n = nums.size();

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = (nums[i] == target) ? 1 : -1;
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += a[j];
                if (sum > 0) ans++;
            }
        }

        return ans;
    }
};