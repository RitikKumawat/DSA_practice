#include<iostream>
#include<stack>

using namespace std;

void sortedInsert(stack<int> &stack, int num){
    if(stack.empty() || (!stack.empty() && stack.top()<num)){
        stack.push(num);
        return;
    }
    int n = stack.top();
    stack.pop();
    sortedInsert(stack,num);
    stack.push(n);
}

void sort(stack<int> &stack){
    if(stack.empty()){
        return;
    }
    int num = stack.top();
    stack.pop();
    sort(stack);
    sortedInsert(stack,num);
}

int main(){
stack<int> Mystack;
Mystack.push(7);
Mystack.push(1);
Mystack.push(4);
Mystack.push(5);


sort(Mystack);
while (!Mystack.empty())    
{
    cout<<Mystack.top()<<endl;
    Mystack.pop();
}
return 0;
}