#include<iostream>
using namespace std;
int main(){
int arr[7]={1,2,3,4,5,6,2};
int duplicate=0;
for(int i=0;i<7;i++){
    duplicate= duplicate^arr[i];
}
for(int i=1;i<7;i++){
    duplicate= duplicate^i;
}
cout<<duplicate<<endl;

return 0;
}