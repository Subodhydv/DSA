class Solution {
public:
    bool checkString(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(!st.empty() && s[i]=='a' && st.top()=='b'){
                return false;
            }
            st.push(s[i]);
            
        }
        return true;
        
    }
};