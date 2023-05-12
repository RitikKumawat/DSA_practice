#include<iostream>
#include<vector>
using namespace std;


void solve(string str, string output,int index, vector<string> &ans){
    if(index>=str.length()){
        if(output.size()>0)
            ans.push_back(output);
        return;
    }

    solve(str,output,index+1,ans);
    char element = str[index];
    output.push_back(element);
    solve(str,output,index+1,ans);

}


vector<string> subsequence(string str){
    int index=0;
    string output;
    vector<string> ans;

    solve(str,output,index,ans);

    return ans;
}
int main(){

string str = "abc";

vector<string> a = subsequence(str);
for(auto i: a){
    cout<<i<<" ";
}cout<<endl;

return 0;
}