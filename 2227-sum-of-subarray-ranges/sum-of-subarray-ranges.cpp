class Solution {
public:

    long long getMin(vector<int>& nums){

        int n = nums.size();

        vector<int> prev(n), next(n);
        stack<int> st;

        // Previous Smaller
        for(int i=0;i<n;i++){

            while(!st.empty() &&
                  nums[st.top()] > nums[i])
                st.pop();

            prev[i] =
                st.empty() ? -1 : st.top();

            st.push(i);
        }

        while(!st.empty())
            st.pop();

        // Next Smaller
        for(int i=n-1;i>=0;i--){

            while(!st.empty() &&
                  nums[st.top()] >= nums[i])
                st.pop();

            next[i] =
                st.empty() ? n : st.top();

            st.push(i);
        }

        long long sum = 0;

        for(int i=0;i<n;i++){

            long long left =
                i - prev[i];

            long long right =
                next[i] - i;

            sum +=
                1LL *
                nums[i] *
                left *
                right;
        }

        return sum;
    }

    long long getMax(vector<int>& nums){

        int n = nums.size();

        vector<int> prev(n), next(n);
        stack<int> st;


        for(int i=0;i<n;i++){

            while(!st.empty() &&
                  nums[st.top()] < nums[i])
                st.pop();

            prev[i] =
                st.empty() ? -1 : st.top();

            st.push(i);
        }

        while(!st.empty())
            st.pop();

   
        for(int i=n-1;i>=0;i--){

            while(!st.empty() &&
                  nums[st.top()] <= nums[i])
                st.pop();

            next[i] =
                st.empty() ? n : st.top();

            st.push(i);
        }

        long long sum = 0;

        for(int i=0;i<n;i++){

            long long left =
                i - prev[i];

            long long right =
                next[i] - i;

            sum +=
                1LL *
                nums[i] *
                left *
                right;
        }

        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {

        long long maxi =
            getMax(nums);

        long long mini =
            getMin(nums);

        return maxi - mini;
    }
};