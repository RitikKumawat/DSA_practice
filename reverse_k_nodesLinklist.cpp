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
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }cout<<"NULL"<<endl;
}


node* KReverse(node* head, int k){
    if(head==NULL){
        return NULL;
    }
    node* next=NULL;
    node* curr=head;
    node* prev=NULL;
    int count=0;

    while(curr!=NULL && count<k){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }

    if(next!=NULL){
        head->next= KReverse(next,k);
    }
    return prev;

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

node* ans = KReverse(head,2);
print(ans);


return 0;
}