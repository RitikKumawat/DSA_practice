#include<iostream>
#include<vector>
using namespace std;

bool check(vector<int> a){
    int count=0;
    for(int i=1;i<a.size();i++){
        if(a[i-1]>a[i])
            count++;
    }
    if(a[a.size()-1]>a[0])
        count++;
    return count==1;
}
int main(){
vector<int> a={3,4,5,1,2};
bool ans = check(a);
if(ans){
    cout<<"It is rotated and sorted array"<<endl;
}
else{
    cout<<"It's not rotated and sorted array"<<endl;
}
return 0;
}