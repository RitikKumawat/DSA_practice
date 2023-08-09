#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main(){
string s= "welcome to coding ninjas";
vector<string> a;
string ans;
string temp="";
for(int i=0;i<s.size();i++){
    if(s[i]==' '){
        a.push_back(temp);
        temp="";
        continue;
    }
    if(i==s.size()-1){
        temp+=s[i];
        a.push_back(temp);
    }
    temp+=s[i];
}
reverse(a.begin(),a.end());

// for(auto i: a){
//     cout<<i<<" ";
// }
for(auto i: a){
    ans+=i;
    ans.push_back(' ');
}
ans.pop_back();
cout<<ans;

return 0;
}