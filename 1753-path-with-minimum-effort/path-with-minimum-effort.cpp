class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>> pq;

        dist[0][0] = 0;
        pq.push({0,{0,0}});

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        while(!pq.empty())
        {
            int diff = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if(row==n-1 && col==m-1)
                return diff;

            for(int i=0;i<4;i++)
            {
                int nr=row+drow[i];
                int nc=col+dcol[i];

                if(nr>=0 && nr<n &&
                   nc>=0 && nc<m)
                {
                    int newEffort =
                        max(diff,
                            abs(heights[row][col]-heights[nr][nc]));

                    if(newEffort < dist[nr][nc])
                    {
                        dist[nr][nc]=newEffort;
                        pq.push({newEffort,{nr,nc}});
                    }
                }
            }
        }

        return 0;
    }
};