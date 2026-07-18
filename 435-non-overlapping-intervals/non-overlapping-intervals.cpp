class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
       sort(intervals.begin(), intervals.end(),
      [](vector<int>& a, vector<int>& b){
         return a[1] < b[1];
     });
        vector<int> prev = intervals[0];
        int cnt=0;
        for(int i=1;i<n;i++){
            int currstarting = intervals[i][0];
            int currending =intervals[i][1];
            int prevstarting= prev[0];
            int prevending=prev[1];
            if(currstarting < prevending){
                cnt++;
            } else{
               prev=intervals[i];
            }
                  }
        
         return cnt;
    }
};