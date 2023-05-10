#include<iostream>
using namespace std;
int main(){
int arr[5]={1,2,7,8,5};
int n=5;
for(int i=0;i<n;i=i+2){
    swap(arr[i],arr[i+1]);

}
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";

}
cout<<endl;
return 0;
}