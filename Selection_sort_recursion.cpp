#include<iostream>
using namespace std;

void Selectionsort(int* arr, int n){
    if(n==0 || n==1)
        return ;

    for(int i=0;i<n;i++){
        if(arr[0]>arr[i])
            swap(arr[0],arr[i]);
    }
    return Selectionsort(arr+1,n-1);
}


int main(){

int arr[]={12,4,3,5,11,2};
int n=6;
Selectionsort(arr,n);
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}cout<<endl;

return 0;
}