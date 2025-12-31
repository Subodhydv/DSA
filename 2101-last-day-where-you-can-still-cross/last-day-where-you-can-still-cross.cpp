class Solution {
public:
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int row, col;

    bool DFS(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == 1) {
            return false;
        }
        if (i == row - 1) {
            return true;
        }
        grid[i][j] = 1;
        for (auto& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            if (DFS(grid, new_i, new_j)) {
                return true;
            }
        }
        return false;
    }

    bool Cross(vector<vector<int>>& cells, int mid) {
        vector<vector<int>> grid(row, vector<int>(col, 0));


        for (int i = 0; i <= mid; i++) {
            int x = cells[i][0] - 1;
            int y = cells[i][1] - 1;
            grid[x][y] = 1;
        }
        for (int j = 0; j < col; j++) {
            if (grid[0][j] == 0 && DFS(grid, 0, j)) {
                return true;
            }
        }
        return false;
    }

    int latestDayToCross(int r, int c, vector<vector<int>>& cells) {
        row = r;
        col = c;

        int l = 0, right = cells.size() - 1, lastday = 0;
        while (l <= right) {
            int mid = l + (right - l) / 2;
            if (Cross(cells, mid)) {
                lastday = mid + 1; 
                l = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return lastday;
    }
};
