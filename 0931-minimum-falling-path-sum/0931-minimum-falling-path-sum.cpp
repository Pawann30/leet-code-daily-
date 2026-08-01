class Solution {
public:
    const int INF = 1e9;
    int solve(int i , int j , int n , vector<vector<int>>& matrix , vector<vector<int>>& dp){
        if(j<0 || j>=n){
            return INF;
        }
        if( i == n-1){
            return matrix[i][j];
        }
        if(dp[i][j]!=INF) 
            return dp[i][j];
       /* int t = min(matrix[i+1][j-1] , min(matrix[i+1][j] , matrix[i+1][j+1])) +solve(i+1 ,j+1 , n ,matrix , dp);
        int l = solve(i+1 ,j+1 , n ,matrix , dp);*/
        int down = solve(i+1,j,n,matrix,dp);
        int left = solve(i+1,j-1,n,matrix,dp);
        int right = solve(i+1,j+1,n,matrix,dp);
        return dp[i][j] = matrix[i][j] + min({down , left , right});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n ,vector<int> (n,INF));
        int ans = INF;
        for (int j = 0; j < n; j++) {
            ans = min(ans, solve(0, j, n, matrix, dp));
        }
        return ans;;
    }
};