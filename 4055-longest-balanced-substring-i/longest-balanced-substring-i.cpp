class Solution {
public:
    int longestBalanced(string s) {
          int n = s.size();
    int mab = 0;

    for(int i = 0; i < n; i++) {
        vector<int> f(26, 0);

        for(int j = i; j < n; j++) {
            f[s[j] - 'a']++;

            int mn = INT_MAX, mx = 0;

            for(int k = 0; k < 26; k++) {
                if(f[k] > 0) {
                    mn = min(mn, f[k]);
                    mx = max(mx, f[k]);
                }
            }

            if(mn == mx) {  
                mab = max(mab, j - i + 1);
            }
        }
    }

    return mab;
    }
};