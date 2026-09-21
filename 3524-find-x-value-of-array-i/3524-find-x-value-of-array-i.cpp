class Solution {
public:
    vector<long long> resultArray(vector<int>& nums,int k){
        vector<long long> ans(k),dp(k),ndp(k);
        for(int x:nums){
            fill(ndp.begin(),ndp.end(),0);
            int a=x%k;
            ndp[a]++;
            for(int r=0;r<k;r++)
                if(dp[r])
                    ndp[(r*a)%k]+=dp[r];
            dp=ndp;
            for(int r=0;r<k;r++)
                ans[r]+=dp[r];
        }
        return ans;
    }
};