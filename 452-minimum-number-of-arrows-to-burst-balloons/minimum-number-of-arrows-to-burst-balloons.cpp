class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(),points.end());
        vector<int> prev = points[0];
        int cnt=1;
        for(int i=1;i<n;i++){
            int currstarting = points[i][0];
            int currending =points[i][1];
            int prevstarting= prev[0];
            int prevending=prev[1];
            if(currstarting > prevending){
                cnt++;
                prev=points[i];
            } else{
                prev[0]=max(prevstarting, currstarting);
                prev[1]=min(prevending,currending);
            }
                  }
        
         return cnt;
        
    }
};