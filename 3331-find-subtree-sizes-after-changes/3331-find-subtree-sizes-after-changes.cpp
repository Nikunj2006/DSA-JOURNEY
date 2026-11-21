class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent,string s) {
        int n=parent.size();
        vector<vector<int>> adj(n),g(n);
        for(int i=1;i<n;i++) adj[parent[i]].push_back(i);

        vector<int> last(26,-1),p(n);
        function<void(int)> dfs=[&](int u){
            int c=s[u]-'a';
            int old=last[c];
            p[u]=(old==-1?parent[u]:old);
            last[c]=u;
            for(int v:adj[u]) dfs(v);
            last[c]=old;
        };
        dfs(0);

        for(int i=1;i<n;i++) g[p[i]].push_back(i);

        vector<int> ans(n,1);
        function<void(int)> calc=[&](int u){
            for(int v:g[u]){
                calc(v);
                ans[u]+=ans[v];
            }
        };
        calc(0);
        return ans;
    }
};