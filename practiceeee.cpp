#include<iostream>
#include<unordered_map>

using namespace std;

char kThCharaterOfDecryptedString(string s, long long k)
{
    //  Write your code here.
    string ans="";
    for(int i=0;i<s.length();i++){
        if(s[i]>='0' && s[i]<='9'){
            int j=i;
            while(s[j]>='a' && s[j]<='z'){
                j--;
            }
            for(int count=0;count<s[i]-'0';count++){
                ans+=s.substr(j,i);
            }

        }
    }

    return ans[k-1];
}
int main(){

// cout<<ans<<endl;

return 0;
}