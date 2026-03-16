class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n=nums.size();
        int x1=0,x2=0;
        for(int i=0;i<n;i++){
            x2=x2^nums[i];
            x1=x1^i;
        }
        x1=x1^n;
        return (x1^x2);
    }
};
