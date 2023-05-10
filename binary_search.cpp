#include<iostream>
#include<vector>
using namespace std;

bool BinarySearch(vector<vector<int>> v, int target){
    int row=v.size();
    int col=v[0].size();

    int start=0;
    int end = row*col -1;

    int mid = start + (end-start)/2;
    while(start<=end){
        int element = v[mid/col][mid%col];
        if(element==target){
            return 1;
        }
        if(element>target){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
        mid = start+(end-start)/2;
    }
    return 0;
}

int main(){
vector<vector<int>> v ={
    {1,3,5,7},
    {10,11,16,20},
    {23,30,34,60}
};

if(BinarySearch(v,30)){
    cout<<"Element found"<<endl;
}
else{
    cout<<"Element not found"<<endl;
}


return 0;
}