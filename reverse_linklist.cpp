#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* next;
    node(int val){
          data = val;
          next=NULL;
          }
};


void print(node* &head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}

int main(){

node* node1= new node(1);
node* node2= new node(2);
node* node3= new node(3);
node* node4= new node(4);

node* head = node1;
node1->next=node2;
node2->next=node3;
node3->next=node4;
node4->next=NULL;
cout<<"Before reversing"<<endl;
print(head);

node* prev = NULL;
node* curr = head;
while(curr!=NULL){
    node* forward = curr->next;
    curr->next=prev;
    prev=curr;
    curr=forward;
}

cout<<"After reversing:"<<endl;
print(prev);

return 0;
}