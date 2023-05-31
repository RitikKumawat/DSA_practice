#include<iostream>
#include<stack>

using namespace std;
int main(){
string str = "ritik";
cout<<"Given String: "<<str<<endl;
stack<char>st;
for(int i=0;i<str.length();i++){
    st.push(str[i]);
}
string ans;
while(!st.empty()){
    ans.push_back(st.top());
    st.pop();
}
cout<<"Reversed String is: "<<ans<<endl;
return 0;
}