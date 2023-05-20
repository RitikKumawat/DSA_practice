#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;

        node(int value){
            data=value;
            next=NULL;
        }
};


node* getMiddle(node* head){
    if(head==NULL || head->next==NULL)
        return head;
    if(head->next->next==NULL)
        return head->next;
    
    node* slow = head;
    node* fast = head->next;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
    }
    return slow;
}
void print(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }cout<<endl;
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
node6->next = NULL;


print(head);
node* middle = getMiddle(head);
cout<<"Middle element of linklist is: "<<middle->data<<endl; 



return 0;
}