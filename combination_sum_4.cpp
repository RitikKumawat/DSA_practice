#include<iostream>
#include<vector>
using namespace std;

// Using Normal Recursion without DP
int combination_sum(vector<int> &num, int target){
    if(target<0)
        return 0;
    if(target==0)
        return 1;

    int ans=0;
    for(int i=0;i<num.size();i++){
        ans+=combination_sum(num,target-num[i]);
    }
    return ans;
}

//Using DP (Recursion + Memoization )
int solveMem(vector<int> &num, int tar, vector<int> &dp){
    if(tar<0)
        return 0;
    if(tar==0)
        return 1;
    if(dp[tar]!=-1)
        return dp[tar];
    int ans=0;
    for(int i=0;i<num.size();i++){
        ans+= solveMem(num,tar-num[i],dp);
    }
    dp[tar]=ans;
    return dp[tar];
}
int comb_sum(vector<int> &num , int target){
    vector<int> dp(target+1,-1);
    return solveMem(num,target,dp);
}

// Using Tabulation DP 
int solveTab(vector<int> &num, int tar){
    vector<int> dp(tar+1,0);
    dp[0]=1;
    for(int i=0;i<=tar;i++){
        for(int j=0;j<num.size();j++){
            if(i-num[j]>=0)
                dp[i] += dp[i-num[j]];
        }
    }
    return dp[tar];
}

int main(){
vector<int> num = {1,2,5};
int target = 5;
// cout<<combination_sum(num,target);
// cout<<comb_sum(num,target);
cout<<solveTab(num,target);

return 0;
}