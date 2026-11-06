class Solution {
    public:
        vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
                sort(logs.begin(),logs.end(),[](auto &a,auto &b){return a[1]<b[1];});
                        vector<pair<int,int>> q;
                                for(int i=0;i<queries.size();i++) q.push_back({queries[i],i});
                                        sort(q.begin(),q.end());

                                                vector<int> cnt(n+1),ans(queries.size());
                                                        int l=0,r=0,active=0;

                                                                for(auto [t,id]:q){
                                                                            while(r<logs.size() && logs[r][1]<=t){
                                                                                            int s=logs[r++][0];
                                                                                                            if(cnt[s]++==0) active++;
                                                                                                                        }
                                                                                                                                    while(l<r && logs[l][1]<t-x){
                                                                                                                                                    int s=logs[l++][0];
                                                                                                                                                                    if(--cnt[s]==0) active--;
                                                                                                                                                                                }
                                                                                                                                                                                            ans[id]=n-active;
                                                                                                                                                                                                    }
                                                                                                                                                                                                            return ans;
                                                                                                                                                                                                                }
                                                                                                                                                                                                                };
