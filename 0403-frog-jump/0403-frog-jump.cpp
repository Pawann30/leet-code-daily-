class Solution {
public:
    bool solve(int i, vector<int>& stones, int k,vector<vector<int>>& dp){
        int n =stones.size();
        if(i == n-1){
            return true;
        }
        if(dp[i][k]!=-1){
            return dp[i][k];
        }
        for(int j= i+1 ; j<n;j++){
            int  jump = stones[j]-stones[i];
            if(jump < k-1){
                continue;
            }if(jump > k +1){
                break;
            }
            if(solve(j,stones,jump,dp)){
                return dp[i][k]=true;
            }
        }
        return dp[i][k]=false;
        /*if(stones[i]-stones[i-1]==k){
            return dp[i]=solve(i+k,stones,stones[i]-stones[i-1],dp);
        }else if(stones[i]-stones[i-1]==k-1){
            return dp[i]=solve(i+k-1,stones,stones[i]-stones[i-1],dp);
        }else if(stones[i]-stones[i-1]==k+1){
            return dp[i]=solve(i+k+1,stones,stones[i]-stones[i-1],dp);
        }
        else{ 
            return false;
        }*/
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if(stones[1]!=1){
            return false;
        }
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        int k;
        return solve(1 , stones , 1 , dp);
    }
};