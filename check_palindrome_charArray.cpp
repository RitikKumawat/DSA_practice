#include<iostream>
#include<string>
#include<vector>
using namespace std;


bool check_Palindrome(vector<char> a){
    int s=0;
    int e=a.size()-1;

    while(s<=e){
        if(a[s]!=a[e]){
            return 0;
        }
        else{
            s++;
            e--;
        }
    }
    return 1;
}
int main(){
vector<char> a ={'a','b','c','b','a'};
if(check_Palindrome(a)){
    cout<<"It's a Palindromic string"<<endl;
}
else{
    cout<<"It's not a Palindromic string"<<endl;
}
string s ;
return 0;
}