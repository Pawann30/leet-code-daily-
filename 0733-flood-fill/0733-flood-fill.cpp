class Solution {
public:
    void dfs(int sr, int sc, int color, int a,vector<vector<int>>& ans ,int row[], int col[]){
        ans[sr][sc] = color;
        int n =ans.size();
        int m =ans[0].size();
        for(int i =0 ; i<4 ;i++){
            int nrow = sr + row[i];
            int ncol = sc + col[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol <m && ans[nrow][ncol] == a && ans[nrow][ncol] != color){
                dfs(nrow ,ncol , color, a, ans, row , col);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image;
        int a = image[sr][sc];
        int row[] = {-1 , 0 , +1, 0};
        int col[] = {0 , +1, 0, -1};
        dfs(sr ,sc ,color , a, ans ,row ,col);
        return ans;
    }
};