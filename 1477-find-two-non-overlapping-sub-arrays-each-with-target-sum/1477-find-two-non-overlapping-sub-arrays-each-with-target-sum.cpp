class Solution {
public:
    int minSumOfLengths(vector<int>& arr,int target){
        int n=arr.size(),sum=0,left=0,ans=INT_MAX;
        vector<int> dp(n,INT_MAX);
        
        for(int right=0;right<n;right++){
            sum+=arr[right];
            while(sum>target) sum-=arr[left++];
            
            if(right>0) dp[right]=dp[right-1];
            
            if(sum==target){
                int len=right-left+1;
                if(left>0 && dp[left-1]!=INT_MAX)
                    ans=min(ans,dp[left-1]+len);
                dp[right]=min(dp[right],len);
            }
        }
        
        return ans==INT_MAX?-1:ans;
    }
};