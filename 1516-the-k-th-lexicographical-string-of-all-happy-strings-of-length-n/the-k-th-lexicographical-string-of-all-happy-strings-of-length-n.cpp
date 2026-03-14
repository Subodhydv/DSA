class Solution {
public:
    vector<string> ans;
    void dfs(string s, int n){ 
        if(s.size() == n){
            ans.push_back(s);
            return;
        }
        for(char c : {'a','b','c'}){
            if(s.empty() || s.back() != c){
                dfs(s + c, n);
            }
        }
    }

    string getHappyString(int n, int k) {  
        dfs("", n);
        if(ans.size() < k) 
            return "";
        return ans[k-1];
    }
};