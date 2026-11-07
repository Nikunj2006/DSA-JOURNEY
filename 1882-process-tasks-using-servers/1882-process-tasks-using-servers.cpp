class Solution {
    public:
        vector<int> assignTasks(vector<int>& servers,vector<int>& tasks) {
                using P=pair<int,int>;
                        using T=pair<long long,int>;
                                priority_queue<P,vector<P>,greater<P>> free;
                                        priority_queue<T,vector<T>,greater<T>> busy;
                                                int n=servers.size(),m=tasks.size();
                                                        vector<int> ans(m);
                                                                for(int i=0;i<n;i++) free.push({servers[i],i});
                                                                        long long time=0;
                                                                                for(int i=0;i<m;i++){
                                                                                            time=max(time,(long long)i);
                                                                                                        while(!busy.empty() && busy.top().first<=time){
                                                                                                                        auto [t,id]=busy.top();
                                                                                                                                        busy.pop();
                                                                                                                                                        free.push({servers[id],id});
                                                                                                                                                                    }
                                                                                                                                                                                if(free.empty()){
                                                                                                                                                                                                time=busy.top().first;
                                                                                                                                                                                                                while(!busy.empty() && busy.top().first<=time){
                                                                                                                                                                                                                                    auto [t,id]=busy.top();
                                                                                                                                                                                                                                                        busy.pop();
                                                                                                                                                                                                                                                                            free.push({servers[id],id});
                                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                                                                    auto [w,id]=free.top();
                                                                                                                                                                                                                                                                                                                                free.pop();
                                                                                                                                                                                                                                                                                                                                            ans[i]=id;
                                                                                                                                                                                                                                                                                                                                                        busy.push({time+tasks[i],id});
                                                                                                                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                                                                                                                        return ans;
                                                                                                                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                                                                                                            };
