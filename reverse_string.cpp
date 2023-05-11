#include<iostream>
using namespace std;

void reverse (string& str, int i, int j){
    if(i>j)
        return;
    swap(str[i],str[j]);
    i++;
    j--;
    return reverse(str,i,j);

}

int main(){

string s = "ritik";
cout<<s<<endl;
reverse(s,0,s.length()-1);
cout<<s<<endl;
return 0;
}