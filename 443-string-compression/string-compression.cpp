class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int i=0;
        int idx=0;
        while(i < n){
            char curr_el=chars[i];
            int cnt=0;
            while(i<n && chars[i]==curr_el){
                cnt++;
                i++;
            }
            chars[idx]=curr_el;
            idx++;
            if(cnt>1){
                string count_str= to_string(cnt);
                for(char & ch:count_str){
                    chars[idx]=ch;
                    idx++;
                }
            }
        }
        return idx;
    }
};