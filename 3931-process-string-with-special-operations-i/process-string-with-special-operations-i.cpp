class Solution {
public:
    string processStr(string s) {
        string s1="";
      for(char ch : s){
        if(islower(ch)){
            s1.push_back(ch);
        }else if( ch=='*'){
            if(!s1.empty()){
                s1.pop_back();
            } }else if(ch=='#'){
                s1+=s1;
            }else if(ch=='%'){
                reverse(s1.begin(),s1.end());
            }
        
      }
      return s1;
        
    }
};