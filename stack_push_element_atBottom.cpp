#include<iostream>
#include<stack>

using namespace std;

stack<int> push_at_bottom(stack<int> &Mystack, int x){
    if(Mystack.empty()){
        Mystack.push(x);
        return Mystack;
    }
    int num = Mystack.top();
    Mystack.pop();
    push_at_bottom(Mystack,x);
    Mystack.push(num);
    return Mystack;
}


int main(){

stack<int> Mystack;
Mystack.push(7);
Mystack.push(1);
Mystack.push(4);
Mystack.push(5);

int x=48;
stack<int> ans = push_at_bottom(Mystack,x);
while (!ans.empty())    
{
    cout<<ans.top()<<endl;
    ans.pop();
}


return 0;
}