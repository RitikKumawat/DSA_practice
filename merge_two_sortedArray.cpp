#include<iostream>
#include<vector>

using namespace std;
int main(){
vector<int> a1 = {1,3,5,7,9};
vector<int> a2 = {2,4,6};
vector<int> a3;

int i=0,j=0;

while(i<a1.size() && j<a2.size()){
    if(a1[i]<a2[j]){
        a3.push_back(a1[i]);
        i++;
    }
    else {
        a3.push_back(a2[j]);
        j++;
    }
}
while(i<a1.size()){
    a3.push_back(a1[i]);
    i++;
}
while(j<a2.size()){
    a3.push_back(a2[j]);
    j++;
}

for(auto m: a3){
    cout<<m<<" ";
}
return 0;
}