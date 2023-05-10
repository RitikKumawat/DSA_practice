#include<iostream>
using namespace std;
int get_max(int num[],int size){
    int max= INT_MIN;
    for(int i=0;i<size;i++){
        if(num[i]>max){
            max=num[i];
        }
    }
    return max;
}
int get_min(int num[],int size){
    int min= INT_MAX;
    for(int i=0;i<size;i++){
        if(num[i]<min){
            min=num[i];
        }
    }
    return min;
}
int main(){
int num[100]={4,12,8,10};
cout<<"MAx element: "<<get_max(num,4)<<endl;
cout<<"MIn element: "<<get_min(num,4)<<endl;
return 0;
}