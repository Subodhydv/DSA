class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lm = 0, rm = 0;
        int sum = 0;
        int l = 0, r = n - 1;
        while (l < r) {
            if (height[l] <= height[r]) {
                if (height[l] < lm) {
                    sum += lm - height[l];
                } else {
                    lm = height[l];
                }
                l++;
            } else {
                if (height[r] < rm) {
                    sum += rm - height[r];
                } else {
                    rm = height[r];
                }
                r--;
            }
        }
        return sum;
    }
};
