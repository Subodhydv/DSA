class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string say=countAndSay(n-1);
        string ans="";
        for(int i=0;i<say.size();i++){
            char cur=say[i];
            int cnt=1;
            while(i<say.size()-1 && say[i]==say[i+1]){
                cnt++;
                i++;
            }
            ans+=to_string(cnt)+string(1,cur);
        }  
        return ans;      
    }
};