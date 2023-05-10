#include<iostream>
#include<vector>

using namespace std;
int main(){
int arr[8]={4,4,2,7,2,1,3,1};
vector<int> res(8,0);
vector<int> ans;
for(int i=0;i<8;i++){
    res[arr[i]]++;
}
// for(int i=0;i<8;i++){
//     cout<<res[i]<<" ";
// }cout<<endl;

for(int i=0;i<8;i++){
    if(res[i]>1){
        ans.push_back(i);
        // cout<<i<<" ";
    }
}cout<<endl;

for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
}cout<<endl;

return 0;
}