#include<iostream>
using namespace std;

int pivot(int arr[], int n){
    int s=0,e=4;
    int mid = s+(e-s)/2;
    while(s<e){
    if(arr[mid]>=arr[0]){
        s=mid+1;
    }
    else{
        e=mid;
    }
    mid = s+(e-s)/2;
}
return s;
}

int main(){
int arr[5]={7,9,1,2,3};
cout<<"Pivot element is  "<<arr[pivot(arr,5)];

return 0;
}