#include<iostream>
#include<vector>
/*
    input 1,2,3,4,5,6,7
    k=3
    output 5,6,7,1,2,3,4
*/ 
using namespace std;
int main(){
vector<int> a={1,2,3,4,5,6,7};
int k=3;
vector<int> temp(a.size());
for(int i=0;i<7;i++){
    temp[(i+k)%a.size()] = a[i];
}
a=temp;
for(auto i: a){
    cout<<i<<" ";
}
return 0;
}