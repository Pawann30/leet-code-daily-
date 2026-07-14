class Solution {
public:
    static const int MOD = 1e9 + 7;
    int solve(vector<int>& nums, int i, int g1, int g2,vector<vector<vector<int>>>& dp) {
        if (i==nums.size()) {
            return (g1 != 0 && g2 != 0 && g1 == g2);
        }
        if (dp[i][g1][g2] != -1) return dp[i][g1][g2];

        long long t1 = solve(nums,i+1,__gcd(g1,nums[i]), g2,dp);
        long long t2 = solve(nums,i+1,g1, __gcd(g2,nums[i]),dp);
        long long skip = solve(nums, i+1,g1,g2,dp);

        return dp[i][g1][g2] = (t1+t2+skip) % MOD;
    }

    int subsequencePairCount(vector<int>& nums) {

        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());

        vector<vector<vector<int>>> dp(n,vector<vector<int>>(mx + 1,vector<int>(mx + 1, -1)));
        return solve(nums, 0, 0, 0, dp);
    }
};