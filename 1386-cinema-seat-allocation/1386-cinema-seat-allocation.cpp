class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,int> mp;
        for(auto &v:reservedSeats)
            mp[v[0]]|=1<<(v[1]-1);

        long long ans=2LL*n;

        for(auto &[row,mask]:mp){
            bool left=(mask&(1<<1))||(mask&(1<<2))||(mask&(1<<3))||(mask&(1<<4));
            bool mid=(mask&(1<<3))||(mask&(1<<4))||(mask&(1<<5))||(mask&(1<<6));
            bool right=(mask&(1<<5))||(mask&(1<<6))||(mask&(1<<7))||(mask&(1<<8));

            if(!left&&!right) continue;
            if(!left||!right){
                ans--;
                continue;
            }
            if(!mid) ans--;
            else ans-=2;
        }

        return ans;
    }
};