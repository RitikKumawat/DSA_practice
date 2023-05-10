#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

vector<char> reverseWord(vector<char>& s){
    reverse(s.begin(),s.end());
    int start=0;
    for(int i=0;i<=s.size();i++){
        if(  s[i]==' ' ){
            reverse(s.begin()+start,s.begin()+i);
            start= i+1;
        }
        else if (i == s.size() - 1) { 
            reverse(s.begin() + start, s.end());
        }
    }
    return s;
}
int main(){
// string s = "My name is ritik";
vector<char> s ={'M','y',' ','n','a','m','e',' ','i','s',' ','r','i','t','i','k'};
vector<char> ans = reverseWord(s);
for(auto i: ans){
    cout<<i;
}
return 0;
}