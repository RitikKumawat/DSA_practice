#include<iostream>
using namespace std;

bool isSorted(int arr[], int size){
    if(size==0 || size==1){
        return true;
    }
    if(arr[0]>arr[1]){
        return false;
    }
    else{
        return isSorted(arr+1, size-1);
    }
}

int main(){
int arr[]={1,2,0,4,5,6};
int size=6;
bool ans = isSorted(arr,size);
if(ans){
    cout<<"sorted array"<<endl;
}
else{
    cout<<"It's not a sorted array"<<endl;
}
return 0;
}