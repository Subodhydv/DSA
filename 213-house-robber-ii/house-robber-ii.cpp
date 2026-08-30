class Solution {
public:
     int robrange(vector<int>& nums,int l, int r){
        int prev2=0;
        int prev1=0;
        for(int i=l;i<=r;i++){
            int take=prev2+nums[i];
            int skip=prev1;
            int cur=max(take,skip);
            prev2=prev1;
            prev1=cur;
        }
        return prev1;
     }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        int case1=robrange(nums,0,n-2);
        int case2=robrange(nums,1,n-1);
        return max(case1,case2);
        
    }
};