#define ll long long
class Solution {
public:
    vector<ll> merge(vector<ll>&left,vector<int>&right){
        ll l = 0,r = 0;
        vector<ll> total;
        while(l<left.size()&&r<right.size()){
            if(left[l]<=right[r]){
                total.push_back(left[l++]);
            }else total.push_back(right[r++]);
        }

        while(l<left.size()){
            total.push_back(left[l++]);
        }
        while(r<right.size()){
            total.push_back(right[r++]);
        }
        return total;
    }
    long long minMergeCost(vector<vector<int>>& lists) {
        ll n = lists.size();

        vector<ll> dp(1LL<<n,1e18);
        // dp[0] = 0;
        vector<vector<ll>> merged(1LL<<n);
        // for(ll i=0;i<n;i++)merged[(1LL)]
        for(ll i=1;i<(1LL<<n);i++){
            for(ll j=0;j<n;j++){
                if(i&(1LL<<j)){
                    merged[i] = merge(merged[i^(1LL<<j)],lists[j]);
                    break;
                }
            }
            // for(auto pos:merged[i]){
            //     cout<<pos<<" ";
            // }
            // cout<<endl;
        }
        for(ll j=0;j<n;j++){
            dp[(1LL<<j)] = 0;
        }
        for(ll i=1;i<(1LL<<n);i++){
            // ll len = __builtin_popcountll(i);
            for(ll j=1;j<(1LL<<n);j++){
                if((j&i)==j){
                    ll other = j^i;
                    if(other>0){
                        ll len = merged[j].size() + merged[other].size();
                        ll sum = merged[j][(merged[j].size()-1)/2] - merged[other][(merged[other].size()-1)/2];
                        dp[i] = min(dp[i],dp[j]+dp[other]+len + abs(sum));
                    }
                }
            }
        }

        for(ll i=1;i<(1LL<<n);i++){
            cout<<dp[i]<<" ";
        }
        cout<<endl;

        return dp[(1LL<<n)-1];
    }
};