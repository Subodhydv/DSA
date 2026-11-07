class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                queue<int> q;
                q.push(i);
                vis[i]=1;
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    for(int i=0;i<n;i++){
                        if(isConnected[node][i]==1 && !vis[i] ){
                            vis[i]=1;
                            q.push(i);

                        }
                    }
                }
            }
        }
        return cnt;
    }
};