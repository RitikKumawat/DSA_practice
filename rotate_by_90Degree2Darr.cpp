#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> Rotate(vector<vector<int>> v, int n){

    // TRANSPOSE THE MATRIX 

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
             swap(v[i][j],v[j][i]);
        }
    }

    //REVERSE EACH ROW
    for(int i=0;i<n;i++){
        for(int j=0;j<n/2;j++){
            swap(v[i][j],v[i][n-j-1]);
        }
    }
    return v;

}

int main(){

vector<vector<int>> v = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
};
int n=3;
cout<<"Before Rotating 90 Degrees"<<endl;
for(auto i: v){
    for( auto j: i){
        cout<<j<<" ";
    }
    cout<<endl;
}
vector<vector<int>> s = Rotate(v,n);
cout<<"After Rotating 90 Degrees"<<endl;
for(auto i: s){
    for( auto j: i){
        cout<<j<<" ";
    }
    cout<<endl;
}

return 0;
}