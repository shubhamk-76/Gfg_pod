#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int solve(int ind,int n,int total,vector<int>&cost,vector<vector<int>>&dp){
        if(total <=0){return 0;}
        if(ind == n){return 0;}
        if(dp[ind][total]!=-1){
            return dp[ind][total];
        }
        int pick=0;
        if(cost[ind]<=total){
            pick=1+solve(ind+1,n,total - cost[ind] + (0.9 * cost[ind]),cost,dp);
        }
        int notpick=0+solve(ind+1,n,total,cost,dp);
        return dp[ind][total]=max(pick,notpick);
    }
    int max_courses(int n, int total, vector<int> &cost)
    {
        //Code Here
       vector<vector<int>>dp(n,vector<int>(total+1,-1));
       int ans=solve(0,n,total,cost,dp);
       return ans;
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.max_courses(n,k,arr)<<endl;
    }
}