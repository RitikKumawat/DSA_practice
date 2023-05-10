#include<iostream>
#include<vector>
using namespace std;
int main(){
vector<int> v = {4,3,1,5,6};
int s = 0;
int e = v.size()-1;

while(s<=e){
    swap(v[s],v[e]);
    s++;
    e--;
}
for(auto i: v){
    cout<<i<<" ";
}
return 0;
}