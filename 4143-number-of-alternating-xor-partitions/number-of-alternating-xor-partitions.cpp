class Solution {
public:
    const int Mod = 1e9 + 7;
    int alternatingXOR(vector<int>& nums, int target1, int target2) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(2,0));
        dp[0][0] = 0;
        dp[0][1] = 1;
        map<int,int> mpp1, mpp2;
        mpp2[0] = 1;
        int xr = 0;
        for(int i = 0; i < n; i++) {
            xr ^= nums[i];
            dp[i + 1][0] = (dp[i + 1][0] + mpp2[xr ^ target1]) % Mod;
            dp[i + 1][1] = (dp[i + 1][1] + mpp1[xr ^ target2]) % Mod;
            mpp1[xr] = (dp[i + 1][0] + mpp1[xr]) % Mod;
            mpp2[xr] = (dp[i + 1][1] + mpp2[xr]) % Mod;
        }
        return (dp[n][0] % Mod + dp[n][1] % Mod) % Mod;
    }
};