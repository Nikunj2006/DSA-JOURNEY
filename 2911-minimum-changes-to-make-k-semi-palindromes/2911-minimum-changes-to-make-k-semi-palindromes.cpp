class Solution {
public:
    int minimumChanges(string s,int k) {
        int n=s.size();
        vector<vector<int>> cost(n,vector<int>(n,1e9));

        for(int l=0;l<n;l++){
            for(int r=l+1;r<n;r++){
                int len=r-l+1;
                for(int d=1;d<len;d++){
                    if(len%d) continue;
                    int cur=0;
                    for(int rem=0;rem<d;rem++){
                        int cnt=(len-1-rem)/d+1;
                        for(int a=0;a<cnt/2;a++){
                            int x=l+rem+a*d;
                            int y=l+rem+(cnt-1-a)*d;
                            if(s[x]!=s[y]) cur++;
                        }
                    }
                    cost[l][r]=min(cost[l][r],cur);
                }
            }
        }

        vector<vector<int>> dp(n+1,vector<int>(k+1,1e9));
        dp[0][0]=0;

        for(int j=1;j<=k;j++){
            for(int i=2*j;i<=n;i++){
                for(int p=2*(j-1);p<=i-2;p++){
                    dp[i][j]=min(dp[i][j],dp[p][j-1]+cost[p][i-1]);
                }
            }
        }

        return dp[n][k];
    }
};