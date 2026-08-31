class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold=INT_MIN;
        int sold=0;
        int prev=0;
        for(auto it:prices){
            int temp=sold;
            sold=max(sold,hold+it);
            hold=max(hold,prev-it);
            prev=temp;
        }
        return sold;
    }
};