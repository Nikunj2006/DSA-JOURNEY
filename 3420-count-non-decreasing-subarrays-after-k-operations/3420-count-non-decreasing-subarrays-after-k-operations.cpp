class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums,int k) {
        int n=nums.size(),LOG=17;
        vector<int> nxt(n+1,n),st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.back()]<=nums[i]) st.pop_back();
            if(!st.empty()) nxt[i]=st.back();
            st.push_back(i);
        }

        vector<vector<int>> up(LOG,vector<int>(n+1,n));
        vector<vector<long long>> sm(LOG,vector<long long>(n+1,0));
        for(int i=0;i<n;i++){
            up[0][i]=nxt[i];
            sm[0][i]=1LL*nums[i]*(nxt[i]-i);
        }

        for(int j=1;j<LOG;j++){
            for(int i=0;i<=n;i++){
                up[j][i]=up[j-1][up[j-1][i]];
                sm[j][i]=sm[j-1][i]+sm[j-1][up[j-1][i]];
            }
        }

        vector<long long> pref(n+1,0);
        for(int i=0;i<n;i++) pref[i+1]=pref[i]+nums[i];

        auto cost=[&](int l,int r){
            long long sum=0;
            int p=l;
            for(int j=LOG-1;j>=0;j--){
                if(up[j][p]<=r+1){
                    sum+=sm[j][p];
                    p=up[j][p];
                }
            }
            if(p<=r) sum+=1LL*nums[p]*(r-p+1);
            return sum-(pref[r+1]-pref[l]);
        };

        long long ans=0;
        int l=0;
        for(int r=0;r<n;r++){
            while(l<=r && cost(l,r)>k) l++;
            ans+=r-l+1;
        }
        return ans;
    }
};