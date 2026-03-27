class Solution {
public:

    int solve(int i,vector<int>& coins,int amount,vector<vector<int>>& dp ){
        if(amount==0) return 0;
        if(i==coins.size()) return 1e9;
        if(dp[i][amount]!=-1) return dp[i][amount];
        int t=1e9;
        if(coins[i]<=amount){
            t=1+solve(i,coins,amount-coins[i],dp);
        }
        int l=solve(i+1,coins,amount,dp);
        return dp[i][amount]=min(t,l);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = solve(0,coins,amount,dp);
        return (ans >= 1e9) ? -1 : ans;

    }
};