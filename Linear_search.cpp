#include<iostream>
using namespace std;
bool present(int arr[],int element, int size){
    for(int i=0;i<size;i++){
        if(arr[i]==element)
            return 1;
    }
    return 0;
}
int main(){
int arr[]={5,7,-2,10,22,-2,0,5,22,1};
cout<<present(arr,1,10)<<endl;
return 0;
}