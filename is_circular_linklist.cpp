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

void print(node* head){
    node* temp=head->next;
    cout<<head->data<<"->";
    while(temp!=head){
        cout<<temp->data<<"->";
        temp=temp->next;
    }cout<<endl;
}


bool isCircular(node* head){
    if(head==NULL){
        return NULL;
    }
    node* temp = head->next;
    while(temp!=NULL && temp!=head){
        temp= temp->next;
    }
    if(temp==head){
        return true;
    }
    
        return false;
    
}

int main(){
node* node1 = new node(1);
node* node2 = new node(2);
node* node3 = new node(3);
node* node4 = new node(4);
node* node5 = new node(5);
node* node6 = new node(6);
node* head=node1;

node1->next = node2;
node2->next = node3;
node3->next = node4;
node4->next = node5;
node5->next = node6;
node6->next = node1;


print(head);
if(isCircular(head)){
    cout<<"It is a circular linked list "<<endl;
}
else{
    cout<<"It's not a circular linked list "<<endl;
}

return 0;
}