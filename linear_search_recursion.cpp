#include<iostream>
using namespace std;

void print(int arr[], int n){
    cout<<"Size of array:"<<n<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}


bool linear(int arr[],int size, int key){
    print(arr,size);
    if(size==0)
        return false;
    if(arr[0]==key)
        return true;
    else
        return linear(arr+1,size-1,key);
}

int main(){

int arr[]={2,45,63,1,4,7};
int size=6;
int key=4;

if(linear(arr,size,key)){
    cout<<"Element found "<<endl;
}
else{
    cout<<"Element not present "<<endl;
}

return 0;
}