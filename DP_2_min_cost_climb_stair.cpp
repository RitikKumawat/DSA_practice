#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;



//Normal Recursion approach - It gives Time Limit Exceed Error
// T.C = O(n^2) 
int solve(vector<int> &cost, int n){
    if(n==0)
        return cost[0];
    if(n==1)
        return cost[1];
    
    int ans = cost[n]+min(solve(cost,n-1),solve(cost,n-2));
    return ans;
}
int mincostClimb(vector<int> &cost){
    int n= cost.size();
    int ans= min(solve(cost,n-1),solve(cost,n-2));
    return ans;
}


// 2nd APproach Recursion + Memoization usin Dynamic Programming
// T.C O(n) S.c O(n)+O(n) = O(n)
int solve2(vector<int> &cost, int n , vector<int> &dp){
    if(n==0)
        return cost[0];
    if(n==1)
        return cost[1];
    if(dp[n]!=-1)
        return dp[n];
    
    dp[n]=cost[n]+ min(solve2(cost,n-1,dp),solve2(cost,n-2,dp));
    return dp[n];
}

int mincostclimb2(vector<int> &cost){
    int n=cost.size();
    vector<int> dp(n+1,-1);
     int ans = min(solve2(cost,n-1,dp),solve2(cost,n-2,dp));
     return ans;
}

// 3rd Approach Tabulation Method using DP
// T.c = O(n) S.C = O(n)

int solve3(vector<int>&cost, int n){
    vector<int> dp(n+1);
    dp[0]=cost[0];
    dp[1]=cost[1];

    for(int i=2;i<n;i++){
        dp[i]= cost[i]+ min(dp[i-1],dp[i-2]);
    }
    return min(dp[n-1],dp[n-2]);
    
}

int mincostclimb3(vector<int> &cost){
    int n=cost.size();
    return solve3(cost,n);
}

// 4th Approach - Space Optimization using Dp by Variables
// T.C O(n)  S.c O(1)
int solve4(vector<int> &cost, int n){
    int prev1= cost[0];
    int prev2= cost[1];

    for(int i=2;i<n;i++){
        int curr = cost[i]+ min(prev1,prev2);
        prev1=prev2;
        prev2=curr;
    }
    return min(prev1,prev2);
}

int mincostclimb4(vector<int> &cost){
    int n=cost.size();

    return solve4(cost,n);
}

int main(){
vector<int> cost = {10,15,20};
cout<<mincostClimb(cost)<<endl;
cout<<mincostclimb2(cost)<<endl;
cout<<mincostclimb3(cost)<<endl;
cout<<mincostclimb4(cost)<<endl;
return 0;
}