class Solution {
public:
    string addBinary(string a, string b) {
        string s;
        int i=a.size()-1;
        int j=b.size()-1;
        int c=0;
        while(i>=0 || j>=0 || c){
            if(i >=0 )
            c+=a[i--]-'0';
         if(j >= 0)
            c+=b[j--]-'0';
            s+=c%2+'0';
            c/=2;
        }
        reverse(begin(s),end(s));
        
        return s;
    }
};