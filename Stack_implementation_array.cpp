#include<iostream>
using namespace std;


class Stack{
    public:
        int *arr;
        int top;
        int size;

        Stack(int size){
            this->size=size;
            arr = new int[size];
            top=-1;
        }
void push(int element){
    if(size-top > -1)
    {
        top++;
        arr[top]=element;
    }    
    else{
        cout<<"Stack Overflow"<<endl;
    }
}

void pop(){
    if(top>=0){
        top--;
    }
    else{
        cout<<"Stack Underflow"<<endl;
    }
}

int seek(){
    if(top>=0 && top<size){
        return arr[top];
    }
    else{
        cout<<"Stack Empty"<<endl;
        return -1;
    }
}

bool isEmpty(){
    if(top==-1){
        return true;
    }
    else{
        return false;
    }
}

void print(){
    for(int i=top;i>=0;i--){
        cout<<arr[i]<<endl;
    }
}

};



int main(){

Stack st(5);
st.push(1);
st.push(2);
st.push(3);
st.push(4);
st.push(5);

// cout<<st.seek()<<endl;

st.print();

return 0;
}