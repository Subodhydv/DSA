class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();

        for(int i = n-2; i >= 0; i--)
        {
            for(int j = 0; j <= i; j++)
            {
                int down = triangle[i+1][j];

                int diagonal = triangle[i+1][j+1];

                triangle[i][j] += min(down, diagonal);
            }
        }

        return triangle[0][0];
    }
};