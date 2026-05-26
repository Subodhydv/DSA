class Solution {
public:
    bool isPalindrome(int x) {
     if( x < 0)
      return false;
     int temp = x;
     long long rev = 0;
     while(x != 0){
        long long d = x%10;
        rev =rev * 10 + d;
        x = x/10;

     }

        return temp==rev;
    }
};