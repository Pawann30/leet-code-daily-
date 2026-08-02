class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int a =0,b=0;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;           
                }
            }
        }
        int count = 0;
        int row[] = {-1 ,0 , +1 , 0};
        int col[] = {0 , 1, 0 , -1};
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int t = q.front().second;
            count =max(count ,t);

            q.pop(); 

            for(int i =0;i<4;i++){
                int nrow = x +row[i];
                int ncol = y +col[i];

                if(nrow>=0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] !=2 ){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol] = 2;
                }
            }
        }
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(vis[i][j]!=2 && grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return count;

    }
};