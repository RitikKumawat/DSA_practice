#include<iostream>
using namespace std;
int main(){
int arr[6]={1,7,9,2,3,0};
int n=6;
for(int i=0;i<n-1;i++){
    int minIndex=i;
    for(int j=i+1;j<n;j++){
        if(arr[j]<arr[minIndex])
            swap(arr[j],arr[minIndex]);
    }
}

for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
    }
return 0;
}