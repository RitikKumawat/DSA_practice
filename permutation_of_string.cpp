#include<iostream>
#include<vector>

using namespace std;

void solve(vector<int> nums, vector<vector<int>> &ans, int index){
    if(index>=nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for(int j=index;j<nums.size();j++){
        swap(nums[index],nums[j]);
        solve(nums,ans,index+1);
        swap(nums[index],nums[j]);
    }
}

vector<vector<int>> permute(vector<int> &nums){
    vector<vector<int>> ans;
    int index=0;
    solve(nums,ans,index);
    return ans;
}

int main(){
vector<int> nums = {1,2,3};

vector<vector<int>> a = permute(nums);

for(auto i: a){
    for(auto j: i){
        cout<<j<<" ";
    }cout<<endl;
}

return 0;
}