#include<iostream>
#include<vector>
#include<stack>
using namespace std;


int celebrity(vector<vector<int>> &M, int n){
    stack<int> s;
    for(int i=0;i<n;i++){
        s.push(i);
    }
    while(s.size()>1){
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if(M[a][b]==1){
            s.push(b);
        }
        else{
            s.push(a);
        }
    }
    int candidate = s.top();
    int zerocount=0;
    bool rowcheck=false;
    for(int i=0;i<n;i++){
        if(M[candidate][i]==0)
            zerocount++;
    }
    if(zerocount==n)
        rowcheck=true;

    int onecount=0;
    bool colcheck=false;
    for(int i=0;i<n;i++){
        if(M[i][candidate]==1)
            onecount++;
    }
    if(onecount==n-1)
        colcheck=true;

    if(rowcheck==true && colcheck==true){
        return candidate;
    }
    else{
        return -1;
    }
}


int main(){

vector<vector<int>> M = {{0,1,0},
                         {0,0,0},
                         {0,1,0}};


cout<<"the celebrity is "<<celebrity(M,3);
return 0;
}