class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),ans=1;
        vector<int> dp(n,1);
        unordered_map<int,int> mp;
        for(int x:nums){
            int a=mp[x-1]+1;
            int b=mp[x]+1;
            mp[x]=max(mp[x],a);
            mp[x+1]=max(mp[x+1],b);
            ans=max(ans,max(mp[x],mp[x+1]));
        }
        return ans;
    }
};