#include<iostream>
#include<string>
using namespace std;

char max_occur(string s){
    int arr[26]={0};
    for(int i=0;i<s.length();i++){
        char ch = s[i];
        int number=0;
        number = ch -'a';
        arr[number]++;
    }
    int max=-1,ans=0;
    for(int i=0;i<26;i++){
        if(max<arr[i]){
            ans=i;
            max = arr[i];
        }
    }
    return 'a'+ans;
}

int main(){
string s = "test";
cout<<max_occur(s);
return 0;
}