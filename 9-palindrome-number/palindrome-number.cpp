class Solution {
public:
    bool isPalindrome(int x) {
        long long  tem=x;
        long long  rev=0;
        while(x>0){
            int d=x%10;
            rev=rev*10+d;
            x=x/10;
        }
       return tem==rev;
    }
};