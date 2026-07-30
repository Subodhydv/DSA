class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
       vector<int> v;
       for( auto &num:matrix){
        for(int it : num){
            v.push_back(it);
        }
       } 
       sort(v.begin(),v.end());
       return v[k-1];
    }
};