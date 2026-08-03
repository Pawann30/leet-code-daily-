class Solution {
public:
    int solve( int i , int j , int k, vector<vector<int>>& grid , vector<vector<vector<int>>>&  dp){
        int n = grid.size();
        int m = grid[0].size();
        if( i >= n || j<0 ||  j >= m || k < 0 || k >= m){
            return -1e9;
        }
        if( i == n-1){
            if( j == k){
                return grid[i][j];
            }
            return grid[i][j] + grid[i][k];
        }
        if(dp[i][j][k] != -1) return dp[i][j][k];
        int ans = 0; 
        for(int a =-1 ;a<=1;a++){
            for(int b = -1; b <= 1; b++){
                int cherry = 0;
                if( j == k){
                    cherry = grid[i][j];
                }else{
                    cherry = grid[i][j]+ grid[i][k];
                }
                cherry += solve( i+1 , j+a , k+b ,  grid ,dp);
                ans = max(ans,cherry);
            }
        }
        return dp[i][j][k] = ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n ,vector<vector<int>>(m ,vector<int> (m ,-1)));
        return solve( 0 , 0 ,m-1 ,  grid ,dp);
    }
};