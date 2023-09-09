#include<iostream>
#include<vector>
using namespace std;

//using recursion , but this solution is not optimized, it is taking too long Time limit exceeds in this solution
int solve(int n){
    if(n==0)
        return 0;
    int ans=n;
    for(int i=1;i*i<=n;i++){
        ans = min(ans,1+solve(n-i*i));
    }
    return ans;
}

//Recursion + Memoization
int solveMem(int n,vector<int> &dp){
    if(n==0)
        return 0;
    if(dp[n]!=-1)
        return dp[n];
    int ans=n;
    for(int i=1;i*i<=n;i++){
        ans=min(ans,1+solveMem(n-i*i,dp));
        
    }
    dp[n]=ans;
    return dp[n];
}

//USing Tabulation method
int solveTab(int n){
    vector<int> dp(n+1,INT_MAX);
    dp[0]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j*j<=n;j++){
            int temp = j*j;
            if(i-temp>=0){
                dp[i] = min(dp[i],1+dp[i-temp]);
            }
        }
    }
    return dp[n];
}

int minSquares(int n){
    // return solve(n);
    // vector<int> dp(n+1,-1);
    // return solveMem(n,dp);
    return solveTab(n);
}

int main(){
cout<<minSquares(100);
return 0;
}