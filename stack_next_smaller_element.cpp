#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> nextSmaller(vector<int> &arr,int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--){
        int curr=arr[i];
        while(s.top()>=curr){
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

vector<int> prevSmaller(vector<int> &arr, int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        int curr=arr[i];
        while(s.top()>=curr){
            s.pop();
        }
        ans[i]=s.top();
        s.push(curr);
    }
    return ans;
}


int main(){
vector<int> a = {2,1,4,3};
vector<int> ans = nextSmaller(a,4);
vector<int> a1 = prevSmaller(a,4);
for(auto i: ans){
    cout<<i<<" ";
}cout<<endl;

for(auto i: a1){
    cout<<i<<" ";
}cout<<endl;


return 0;
}