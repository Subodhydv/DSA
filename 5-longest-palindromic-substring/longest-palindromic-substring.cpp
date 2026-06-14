class Solution {
      void expand(string &s,int l,int r, int &start,int &maxlen){
        while(l>=0 && r<s.size()&& s[l]==s[r]){
            int len=r-l+1;
            if(len>maxlen){
                maxlen=len;
                start=l;
            }
            l--;
            r++;
        }
      };
public:
    string longestPalindrome(string s) {
        int start=0;
        int maxlen=1;
        for(int i=0;i<s.size();i++){
            expand(s,i,i,start,maxlen);
            expand(s,i,i+1,start,maxlen);
        }
        return s.substr(start,maxlen);
        
    }
};