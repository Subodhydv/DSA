class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int Maxare = 0;

        for(int row = 0; row < n; row++) {

            for(int col = 0; col < m; col++) {
                if(matrix[row][col] == 1 && row > 0) {
                    matrix[row][col] += matrix[row-1][col];
                }
            }

            vector<int> heights = matrix[row];

            sort(heights.begin(), heights.end(), greater<int>());

            for(int i = 0; i < m; i++) {
                int base = i + 1;
                int height = heights[i];
                Maxare = max(Maxare, base * height);
            }
        }

        return Maxare;
    }
};