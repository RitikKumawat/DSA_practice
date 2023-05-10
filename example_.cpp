#include<iostream>
using namespace std;
int main(){
char ch = 'A';
for(int i=5;i>=1;i--){
    for(int j=0;j<i;j++){
        cout<<ch;
    }
    cout<<endl;
}
return 0;
}