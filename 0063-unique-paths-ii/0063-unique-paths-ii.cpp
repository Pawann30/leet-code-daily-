class Solution {
public:
    int solve(int i ,int j,vector<vector<int>>& grid, vector<vector<int>>& dp ){
        int n = grid.size();
        int m = grid[0].size();
        if(i >=  n || j >= m){
            return 0;
        }
        if(grid[i][j]==1){
            return 0;
        }
        if(i == n-1 && j == m-1){
            return 1;
        }
        int side = 0;
        int down = 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(grid[i][j] != 1){
            side = solve( i , j+1 , grid , dp);
            down = solve(i+1 , j , grid ,dp);
        }
        return dp[i][j] = side + down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n , vector<int> (m,-1));
        return solve( 0 , 0 , grid , dp);
    }
};