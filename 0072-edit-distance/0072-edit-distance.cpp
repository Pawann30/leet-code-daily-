class Solution {
public:

    int solve(int n,int m, int i, int j,string& w1,string& w2,vector<vector<int>>& dp ){
        if(i == n) return m-j;
        if(j == m) return n-i;
        if(dp[i][j]!=-1) return dp[i][j];
        int t,l;
        if(w1[i]==w2[j]){
            return dp[i][j]=solve(n,m,i+1,j+1,w1,w2,dp);
        }
        int inst=1+solve(n,m,i,j+1,w1,w2,dp);
        int del=1+solve(n,m,i+1,j,w1,w2,dp);
        int rep=1+solve(n,m,i+1,j+1,w1,w2,dp);
        return dp[i][j]=min({inst,del,rep});
    }
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return solve(n,m,0,0,word1,word2,dp);
    }
};