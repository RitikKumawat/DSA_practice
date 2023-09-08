#include<iostream>
#include<vector>

using namespace std;

//Using SImple Recursion
// int solve(vector<int> &weight, vector<int> &value, int index , int capacity){
//     if(index==0){
//         if(weight[0]<=capacity)
//             return value[0];
//         else    
//             return 0;
//     }

//     int include=0;
//     if(weight[index]<=capacity)
//         include = value[index]+solve(weight,value,index-1,capacity-weight[index]);
//     int exclude = 0+ solve(weight,value,index-1,capacity);
//     int ans = max(include,exclude);
//     return ans;
// }


//USing DP => Recursion + Memoization
int solveMem(vector<int> weight, vector<int> value, int index, int capacity, vector<vector<int>> &dp){
    if(index==0){
        if(weight[0]<=capacity){
            return value[0];
        }
        else{
            return 0;
        }
    }
    int include=0;
    if(weight[index] <= capacity)
        include = value[index] + solveMem(weight,value,index-1,capacity-weight[index],dp);
    int exclude = 0 + solveMem(weight, value, index-1, capacity, dp);
    dp[index][capacity] = max(include,exclude);

    return dp[index][capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n , int maxWeight){
    // return solve(weight,value,n-1,maxWeight);
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));

    return solveMem(weight,value,n-1,maxWeight,dp);
}

int main(){

vector<int> weight = {1,2,4,5};
vector<int> value = {5,4,8,6};

cout<<knapsack(weight,value,4,5);

return 0;
}