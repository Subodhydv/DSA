class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        long long n = nums.size();
        vector<long long> prefixGcd(n);
        long long mx = nums[0];
        for(long long i = 0; i < n; i++){
            mx = max(mx, (long long)nums[i]);
            prefixGcd[i] = __gcd((long long)nums[i], mx);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        long long l = 0;
        long long r = n - 1;
        long long ans = 0;
        while(l < r){
            ans += __gcd(prefixGcd[l], prefixGcd[r]);
            l++;
            r--;
        }

        return ans;
    }
};