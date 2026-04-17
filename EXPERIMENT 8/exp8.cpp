class Solution {
    int hello(int i,int j,vector<int>&arr,vector<vector<int>>&dp){
        if(i==j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int mini=1e9;
        
        for(int k=i;k<j;k++){
            int steps= arr[i-1]*arr[k]*arr[j] +hello(i,k,arr,dp)+hello(k+1,j,arr,dp);
            mini=min(mini,steps);
            dp[i][j]=mini;
        }
        return dp[i][j];
    }
  public:
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return hello(1,n-1,arr,dp);
    }
};