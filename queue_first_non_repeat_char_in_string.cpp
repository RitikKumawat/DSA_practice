#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

string first_non_repeat(string A){
    string ans ="";
    unordered_map<char,int> count;
    queue<int> q;
    for(int i=0;i<A.length();i++){
        char ch = A[i];
        count[ch]++;
        q.push(ch);
        while(!q.empty()){
            if(count[q.front()]>1)
                q.pop();
            else{
                ans.push_back(q.front());
                break;
            }
        }
        if(q.empty()){
            ans.push_back('#');
        }
    }
    return ans;
}

int main(){
string a = "aabc";
cout<<a<<endl;
string ans = first_non_repeat(a);
cout<<ans<<endl;
return 0;
}