class Solution {
    bool possible(vector<int>& bloomDay,int day,int m,int k){
        long long  cnt=0;
        long long  no_of_bk=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<= day){
                cnt++;

            }else{
                no_of_bk += cnt/k;
                cnt=0;
        
            }
        }
        no_of_bk += cnt/k;
        return no_of_bk>=m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
     long long req = 1LL * m * k;

     if(req > bloomDay.size())
    return -1;
        long long low=*min_element(bloomDay.begin(),bloomDay.end());
        long long high=*max_element(bloomDay.begin(),bloomDay.end());
          long long ans=high;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(possible(bloomDay, mid, m,k)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};