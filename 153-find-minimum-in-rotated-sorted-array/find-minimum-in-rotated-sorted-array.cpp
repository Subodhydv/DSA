#include<bits/stdc++.h>
class Solution {
public:
    int findMin(vector<int>& arr) {
        long long low = 0, high = arr.size() - 1;
    long long  ans = INT_MAX;
    while (low < high) {
        long long mid = (low + high) / 2;
        if (arr[mid] > arr[high]) {
            low=mid+1;
        }else{
            high=mid;
        }
    }
    return arr[low];
  
    }
};