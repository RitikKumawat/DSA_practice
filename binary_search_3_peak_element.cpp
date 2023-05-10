#include<iostream>
using namespace std;

int peak_element(int arr[],int n){
    int s=0,e=n-1;
    int mid = s+ (e-s)/2;
    
    while(s<e){
        if(arr[mid]<arr[mid+1]){
            s=mid+1;
        }
        else if(arr[mid]>arr[mid+1]){
            e=mid;
        }
        mid = s+(e-s)/2;
    }
    return s;
}
int main(){
int arr[7]={0,2,7,5,4,3,1};
cout<<"peak element is: "<<arr[peak_element(arr,7)]<<endl;
return 0;
}