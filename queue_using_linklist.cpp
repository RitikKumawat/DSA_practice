#include<iostream>

using namespace std;

class node{
    public:
        int data;
        node* next;

        node(int val){
            data=val;
            next=NULL;
        }
};
class Queue{
    public:
        node* rear;
        node* front;
        Queue(){
            front=rear=NULL;
        }
        void enque(int element){
           node* temp =  new node(element);
           if(rear == NULL){
            rear=front=temp;
            return;
           }
           rear->next=temp;
           rear=temp;
        }
        void dequeue(){
            if(front==NULL){
                return ;
            }
            node* temp = front;
            front=front->next;
            if(front==NULL){
                rear=NULL;
            }
            delete(temp);
        }

        void display(){
            node* temp=front;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp=temp->next;
            }cout<<endl;
        }
};

int main(){

Queue q;
q.enque(1);
q.enque(2);
q.enque(3);
q.enque(4);
q.enque(5);
q.display();
q.dequeue();
q.dequeue();

q.display();
return 0;
}