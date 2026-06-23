class Solution {
public:
 void dfs(int row, int col,vector<vector<char>>& grid, vector<vector<int>>& vis ){
    int n=grid.size();
    int m=grid[0].size();
       vis[row][col]=1;
    int drow[]={1,0,-1,0};
 int dcol[] = {0,1,0,-1};
    for(int i=0;i<4;i++){
        int nr=row+drow[i];
        int nc=col+dcol[i];
        if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='1'&& !vis[nr][nc]){
            dfs(nr,nc,grid,vis);
        }
    }

 }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
    int m=grid[0].size();
    int cnt=0;
      vector<vector<int>> vis(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='1' && !vis[i][j]){
                cnt++;
                dfs(i,j,grid,vis);
            }
            
        }
    }
    return cnt;
        
    }
};