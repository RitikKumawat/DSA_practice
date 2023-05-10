#include<iostream>
using namespace std;
/*
    statement= You have given an array of size N, where N is equal to 2M+1
    now in the given array M numbers are repeated twice and 1 number appears only once
    Find that one element

    input = arr{2,3,1,6,3,6,2}
    output {1}

    solution Xor all the elements of array 
    = 2^3^1^6^3^6^2
    = 1
*/

int main(){
int arr[7]={2,3,9,6,3,6,2};
int ans=0;
for(int i=0;i<7;i++){
    ans=ans^arr[i];
}
for(int i=0;i<7;i++){
    cout<<arr[i]<<" ";
}cout<<endl;
cout<<ans<<endl;

return 0;
}