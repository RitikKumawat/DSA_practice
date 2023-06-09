#include<iostream>
#include<stack>
#include<queue>
using namespace std;

queue<int> reverse_K(queue<int> q,int k){
    stack<int> s;
    for(int i=0;i<k;i++){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    int t = q.size()-k;
    while(t--){
        q.push(q.front());
        q.pop();
    }
    return q;
}
int main(){

queue<int> a ;
a.push(1);
a.push(2);
a.push(3);
a.push(4);
a.push(5);

queue<int> ans = reverse_K(a,3);
while(!ans.empty()){
    cout<<ans.front()<<" ";
    ans.pop();
}cout<<endl;
return 0;
}