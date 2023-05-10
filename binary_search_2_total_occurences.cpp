#include<iostream>
using namespace std;

int first_occurence(int arr[], int n, int key){
    int s=0,e=n-1;
    int ans=-1;
    int mid = s+(e-s)/2;
    while(s<=e){
        if(arr[mid]==key){
            ans = mid;
            e=mid-1;
        }
        else if(arr[mid]>key){
            e=mid-1;
        }
        else if(arr[mid]<key){
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}
int last_occurence(int arr[], int n, int key){
    int s=0,e=n-1;
    int ans=-1;
    int mid = s+(e-s)/2;
    while(s<=e){
        if(arr[mid]==key){
            ans = mid;
            s=mid+1;
        }
        else if(arr[mid]>key){
            e=mid-1;
        }
        else if(arr[mid]<key){
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}

int main(){
int arr[7]={1,2,3,3,3,3,5};
int key=3;
cout<<"first_occurence:"<<first_occurence(arr,7,key)<<endl;
cout<<"last_occurence:"<<last_occurence(arr,7,key)<<endl;
cout<<"Total number of occurence of "<<key<<" is: "<<(last_occurence(arr,7,key)-first_occurence(arr,7,key))+1<<endl;

return 0;
}