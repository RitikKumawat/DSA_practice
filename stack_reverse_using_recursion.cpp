#include<stack>
#include<iostream>
using namespace std;

void insertAtBottom(stack<int> &s, int x){
    if(s.empty()){
        s.push(x);
        return;
    }
    int num= s.top();
    s.pop();
    insertAtBottom(s,x);
    s.push(num);
}
void reverse(stack<int> &stack){
    if(stack.empty()){
        return;
    }
    int num=  stack.top();
    stack.pop();
    reverse(stack);
    insertAtBottom(stack,num);

}


int main(){

stack<int> Mystack;
Mystack.push(7);
Mystack.push(1);
Mystack.push(4);
Mystack.push(5);


reverse(Mystack);
while (!Mystack.empty())    
{
    cout<<Mystack.top()<<endl;
    Mystack.pop();
}


return 0;
}