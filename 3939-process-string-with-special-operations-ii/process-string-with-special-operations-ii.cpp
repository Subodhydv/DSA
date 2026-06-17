class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        vector<long long> sz(n);

        long long len = 0;

        for (int i = 0; i < n; i++) {
            char c = s[i];

            if ('a' <= c && c <= 'z') {
                len++;
            }
            else if (c == '*') {
                if (len > 0) len--;
            }
            else if (c == '#') {
                len *= 2;
            }

            sz[i] = len;
        }

        if (k >= len)
            return '.';

        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];
            long long cur = sz[i];

            if ('a' <= c && c <= 'z') {
                if (k == cur - 1)
                    return c;
                len--;
            }
            else if (c == '*') {
                len++;
            }
            else if (c == '#') {
                long long half = cur / 2;
                k %= half;
                len = half;
            }
            else { 
                k = cur - 1 - k;
            }
        }

        return '.';
    }
};