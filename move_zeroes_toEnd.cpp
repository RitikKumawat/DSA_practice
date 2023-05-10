#include<iostream>
#include<vector>
using namespace std;
int main(){
vector<int> a ={2,0,1,3,0,0,0};
// Output 2,1,3,0,0,0,0

int i=0;
for(int j=0;j<a.size();j++){
    if(a[j]!=0){
        swap(a[j],a[i]);
        i++;
    }
}

for(auto m: a){
    cout<<m<<" ";
}
return 0;
}