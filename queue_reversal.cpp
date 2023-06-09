#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverse(queue<int> &q){
    stack<int> s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    // return q;
}
int main(){
queue<int> q;
q.push(1);
q.push(2);
q.push(3);
q.push(4);

reverse(q);
while(!q.empty()){
    cout<<q.front()<<" ";
    q.pop();
}cout<<endl;

return 0;
}