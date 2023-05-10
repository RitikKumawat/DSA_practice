#include<iostream>
#include<string>
using namespace std;

string replace_Space(string &str){
    string temp = "";
    for(int i=0; i<str.length();i++){
        if(str[i]==' '){
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        }
        else{
            temp.push_back(str[i]);
        }
    }
    return temp;
}
int main(){
string str = "It was nice meeting you";
cout<<str<<endl;
cout<<replace_Space(str)<<endl;
return 0;
}