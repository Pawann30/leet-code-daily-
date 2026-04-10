class Solution {
public:
    int solve(int n,int idx,vector<int>& j,int d,vector<vector<int>>& dp){
        if(d == 1){
            int mx=INT_MIN;
            for(int i=idx;i<n;i++){
                mx=max(mx,j[i]);
            }
            return mx;
        }
        if(dp[idx][d]!=-1) return dp[idx][d];
        int mx=INT_MIN;
        int res =0;
        int fres=INT_MAX;
        if(dp[idx][d]!=-1) return dp[idx][d];
        for(int i=idx;i<=n-d;i++){
            mx=max(j[i],mx);
            res = mx + solve(n,i+1,j,d-1,dp);
            fres=min(fres,res);
        }
        return dp[idx][d]=fres;
    }

    int minDifficulty(vector<int>& j, int d) {
        int n = j.size();
        if(d>n) return -1;
        vector<vector<int>> dp(n,vector<int>(d+1,-1));
        return solve(n,0,j,d,dp);
    }
};