#include<iostream>
using namespace std;

int first_occurence(int arr[],int s, int e, int k){
    if(e>=s){
        int mid = s+(e-s)/2;
        if( (mid==0 || k > arr[mid-1]) && arr[mid]==k )
            return mid;
        else if(k>arr[mid])
            return first_occurence(arr,mid+1,e,k);
        else    
            return first_occurence(arr,s,mid-1,k);
    }
    return -1;
}

int last_occurence(int arr[],int s, int e, int k){
    if(e>s){
        int mid = s+(e-s)/2;
        if( (mid==e || k < arr[mid]) && arr[mid]==k )
            return mid;
        else if(k<arr[mid])
            return first_occurence(arr,s,mid-1,k);
        else    
            return first_occurence(arr,mid+1,e,k);
    }
    return -1;
}




int main(){
int arr[]={0,1,1,5};
int size = 4;
int k=1;

cout<<"First occurence of "<<k<<" is at index:"<<first_occurence(arr,0,3,k)<<endl;
cout<<"Last occurence of "<<k<<" is at index:"<<last_occurence(arr,0,3,k)<<endl;

return 0;
}