#include<iostream>
using namespace std;

int First_occur(int arr[],int n, int key){
    int s=0,e=n-1;
    int mid= s+(e-s)/2;
    int ans=-1;

    while(s<=e){
        if(arr[mid]==key){
            ans=mid;
            e=mid-1;
        }
        else if(arr[mid]<key){
            s=mid+1;
        }
        else if(arr[mid]>key){
            e=mid-1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}
int Last_occur(int arr[],int n, int key){
    int s=0,e=n-1;
    int mid= s+(e-s)/2;
    int ans=-1;

    while(s<=e){
        if(arr[mid]==key){
            ans=mid;
            s=mid+1;
        }
        else if(arr[mid]<key){
            s=mid+1;
        }
        else if(arr[mid]>key){
            e=mid-1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}

int main(){
int arr[5]={1,2,3,3,5};
int key=3;
int f= First_occur(arr,5,key);
int l= Last_occur(arr,5,key);
cout<<"First occurence of "<<key<<" is "<<f<<" and the last occurence of "<<key<<" is "<<l<<endl;


return 0;
}