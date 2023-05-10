#include<iostream>
using namespace std;
int binary_Search(int arr[],int size,int key){
    int start=0;
    int end=size-1;
    int mid = (start+end)/2;

    while(start<=end){
        if(arr[mid]==key){
            return mid;
        }
        if(key>mid){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=(start+end)/2;
    }
    return -1;
}
int main(){
int arr[5]={3,5,9,13,25};
int index= binary_Search(arr,5,13);
cout<<index<<endl;
return 0;
}