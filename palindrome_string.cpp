#include<iostream>
#include<string>
using namespace std;

bool valid(char ch){
    if(  (ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')   ){
        return 1;
    }
    return 0;
}

char tolowercase(char ch){
    if((ch>='a' && ch<='z') || (ch>='0' && ch<='9') ){
        return ch;
    } 
    else{
        char tmp  = ch -'A'+'a';
        return tmp;
    }
}
bool checkPalindrome(string a){
    int s=0;
    int e= a.length()-1;

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
bool isPalindrome(string s){
    string temp = "";
    // Step1 : removing characters from array
    for(int i=0;i<s.length();i++){
        if(valid(s[i])){
            temp.push_back(s[i]);
        }
    }
    // Step2 : converting to lowercase 
    for(int i=0;i<temp.length();i++){
        temp[i]= tolowercase(temp[i]);
    }
    cout<<temp<<endl;

    // Step3 : checking palindrome
    return checkPalindrome(temp);

}
int main(){
string s = "A man, a plan, a canal: Panama";
cout<<s<<endl;
cout<<isPalindrome(s);

return 0;
}