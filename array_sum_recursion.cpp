#include<iostream>
using namespace std;

int count(int arr[], int size){
    
    
    if(size==0){
        return 0;
    }
    
    
        return arr[0] + count(arr+1, size-1);
    
}
int main(){

int arr[]={1,2,2,4,6,2};
int size=6;

cout<<count(arr,size);

return 0;
}