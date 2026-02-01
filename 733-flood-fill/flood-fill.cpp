class Solution {
private:
    void dfs(int row, int col, vector<vector<int>> &ans,
             vector<vector<int>>& image, int newColor, int initialColor,
             int dx[], int dy[]) 
    {
        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();
        
        for (int i = 0; i < 4; i++) {
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                image[nrow][ncol] == initialColor && ans[nrow][ncol] != newColor) 
            {
                dfs(nrow, ncol, ans, image, newColor, initialColor, dx, dy);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int dx[4] = {-1, 0, +1, 0};
        int dy[4] = {0, +1, 0, -1};

        if (initialColor != color) {
            dfs(sr, sc, ans, image, color, initialColor, dx, dy);
        }

        return ans;
    }
};
