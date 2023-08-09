#include<iostream>
#include<string>
using namespace std;

void printSubstrings(string input){
    int n=input.size();
    for(int i=0;i<n;i++){
        string temp="";
        for(int j=i;j<n;j++){
            temp+=input[j];
            cout<<temp<<endl;
        }
    }
}

int main(){
string str="abcd";
cout<<"given string "<<str<<endl;
cout<<"All Substrings:"<<endl;
printSubstrings(str);
return 0;
}