class Solution {
public:
    int largestAltitude(vector<int>& gain) {
       int cur=0;
       int maxi=0;
       for(auto x:gain){
        cur+=x;
        maxi=max(maxi,cur);
       }
       return maxi;
    }
};