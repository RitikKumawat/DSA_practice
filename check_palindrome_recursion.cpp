#include<iostream>
using namespace std;

bool checkPalindrome(string& str, int i, int j){
    if(i>=j)
        return true;
    if(str[i]!=str[j])
        return false;
    else
        return checkPalindrome(str,i+1,j-1);
}

int main(){

string s = "baabaab";

if(checkPalindrome(s,0,s.length()-1))
{
    cout<<"It is a Palindrome"<<endl;

}
else{
    cout<<"It's not a Palindrome"<<endl;
}
return 0;
}