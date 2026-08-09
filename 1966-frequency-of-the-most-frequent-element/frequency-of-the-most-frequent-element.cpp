class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int left=0;
        long cur=0;
        int ans=0;
        for(int right=0;right<nums.size();right++){
            long target=nums[right];
            cur+=target;
            while((right-left+1)*target-cur>k){
                cur-=nums[left];
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};