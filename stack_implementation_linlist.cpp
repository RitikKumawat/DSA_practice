#include<iostream>
using namespace std;



class Node{
    public:
    int data;
    Node* next;
};

class Stack{
        private:
        
        Node* top;

        
        public:
        Stack(){
            top=nullptr;
        }

        bool isEmpty(){
            return (top==nullptr);
        }

        void push(int val){
            
            Node* newnode = new Node();
            newnode->data = val;
            newnode->next=nullptr;
            
            if(isEmpty()){
                top=newnode;
            }
            else{
                newnode->next=top;
                top=newnode;
            }   
            cout<<val<<" Pushed to stack"<<endl;
        }

        int pop(){
            if(isEmpty()){
                cout<<"!!!!ERROR!!!!!Stack Underflow....."<<endl;
                return -1;
            }
            Node* temp=top;
            int popped_ele = temp->data;
            top=top->next;
            delete temp;

            return popped_ele;
        }
        void display(){
            if(isEmpty()){
                cout<<"Empty Stack----INsert some element first"<<endl;
                return ;
            }
            cout<<"Stacked elements"<<endl;
            Node* current = top;
            while(current!=nullptr){
                cout<<current->data<<" ";
                current=current->next;
            }cout<<endl;

        }
};

int main(){

Stack stack;

stack.push(10);
stack.push(20);
stack.push(30);
stack.push(40);

stack.display();

cout<<"Popped element "<<stack.pop()<<endl;
stack.display();

return 0;
}