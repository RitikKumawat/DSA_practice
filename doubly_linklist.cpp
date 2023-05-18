#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* prev;
    node* next;
    node(int val){
          data = val;
          prev=NULL;
          next=NULL;
          }

    ~node(){
        int val = this->data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"Memory free for node with data "<<val<<endl;
    }

};


void insertAtHead(node* &head,int d){
    node* temp= new node(d);
    if(head==NULL)
    {
        head=temp;
    }    
    head->prev=temp;
    temp->next=head;
    head=temp;
}


void insertAtTail(node* &tail, int d){
    node* temp = new node(d);
    if(tail==NULL)
    {
        tail=temp;
    }
    tail->next=temp;
    temp->prev=tail;
    tail=temp;

}

void insertAtPosition(int position,int d, node* &head, node* &tail){
    node* insertednode = new node(d);
    
    if(position==1){
        insertAtHead(head,d);
        return;
    }
    
    node* temp = head;
    int cnt=1;
    while(cnt<position-1){
        cnt++;
        temp=temp->next;   
    }
    if(temp->next==NULL){
        insertAtTail(tail,d);
    }
    else{

    insertednode->next=temp->next;
    insertednode->prev=temp;
    temp->next=insertednode;
    }
}

void deletion(int position, node* &head, node* &tail){
    
    if(position==1){
        node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else{

    node* curr = head;
    node* prev = NULL;
    
    int cnt=1;
    while(cnt<position){
        prev=curr;
        curr=curr->next;
        cnt++;
    }

    prev->next=curr->next;
    curr->next=NULL;
    delete curr;

    }

}

void print(node* head){
    node* temp =head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }cout<<"NULL";
    cout<<endl;
}
int main(){
node* node1 = new node(10);
node* head = node1;
node* tail = node1;

print(head);

insertAtHead(head,20);
print(head);

insertAtTail(tail,30);
print(node1);

insertAtTail(tail,40);
print(head);

insertAtPosition(3,100,head,tail);
print(head);

insertAtPosition(5,200,head,tail);
print(head);

insertAtPosition(7,700,head,tail);
print(head);

deletion(2,head,tail);

print(head);

return 0;

}