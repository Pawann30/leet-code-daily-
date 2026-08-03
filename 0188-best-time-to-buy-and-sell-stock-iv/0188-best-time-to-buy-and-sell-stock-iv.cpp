class Solution {
public:
    int solve( int i ,int j ,int k,vector<int>& prices, vector<vector<vector<int>>>& dp){
        int n = prices.size();
        if( i == n || k == 0 ){
            return 0;
        }
        if(dp[i][j][k] != -1) return dp[i][j][k]; 

        if(j){
            int take = -prices[i] + solve(i+1 , 0 , k, prices ,dp);
            int skip = solve(i+1 , 1 , k ,prices ,dp);
            
            return dp[i][j][k] = max(take,skip);
        }else{
            int sell = prices[i] + solve(i+1 , 1 , k-1 , prices ,dp);
            int skip = solve(i+1 , 0 , k , prices ,dp); 

            return dp[i][j][k] = max(sell,skip);  
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp (n , vector<vector<int>> (2 ,vector<int> (k+1 ,-1)));
        return solve( 0 ,1 , k,  prices , dp );
    }
};