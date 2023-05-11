#include<iostream>
using namespace std;

void bubbleSort(int* arr, int n){
    if(n==0 || n==1)
        return ;

    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1])
            swap(arr[i],arr[i+1]);

    }
    return bubbleSort(arr,n-1);
}

int main(){

int arr[]={12,4,3,5,11,2};
int n=6;
bubbleSort(arr,n);
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}cout<<endl;

return 0;
}