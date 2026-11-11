class Solution {
public:
    long long minimumCost(int cost1,int cost2,int costBoth,int need1,int need2) {
        long long a=min(costBoth,cost1+cost2);
        long long ans=0;
        int common=min(need1,need2);
        ans+=(long long)common*a;
        need1-=common;
        need2-=common;
        ans+=(long long)need1*min(cost1,costBoth);
        ans+=(long long)need2*min(cost2,costBoth);
        return ans;
    }
};