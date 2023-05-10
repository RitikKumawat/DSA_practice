#include<iostream>
#include<vector>
using namespace std;


int main(){

vector<vector<int>> v = { 
    {1,2,3},
    {4,5,6},
    {7,8,9}
};

for(auto row: v){
    for(auto element: row){
        cout<<element<<" ";
    }
    cout<<endl;

}

for(int i=0;i<3;i++){
    if(i&1){

        for(int j=2;j>=0;j--){
            cout<<v[i][j]<<" ";
        }
    
    }
    else{
        for(int j=0;j<3;j++){
            cout<<v[i][j]<<" ";
        }
       
    }
    
    
}


return 0;
}