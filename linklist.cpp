#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

    Node(int data){
        this->data = data;
        this->next=NULL;
    }

    ~Node(){
        int value = this->data;

        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"Memory is freed for the node with data:"<<value<<endl;
    }
};
void insertAtHead(Node* &head,int d){
    Node* temp = new Node(d);
    temp->next=head;
    head=temp;
}


void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail->next =temp;
    tail = temp; 
}

void insertAtPosition(Node* &head,Node* &tail, int position, int d){
    int cnt=1;
    Node* temp = head;
    Node* insertednode = new Node(d);
    if(position==1){
        insertAtHead(head,d);
        return;
    }
    while(cnt<position-1){    
        temp = temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        insertAtTail(tail,d);
    }
    insertednode->next = temp->next;
    temp->next = insertednode;

}

void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}

void deletion(int position, Node* &head){
    
    if(position==1){
        Node* temp = head;
        head= head->next;
        temp->next=NULL;
        delete temp;
    }
   else{

    Node* curr = head;
    Node* prev = NULL;
    
    int cnt=1;

    while(cnt<position){
        prev = curr;
        curr=curr->next;
        cnt++;
    }
    prev->next = curr->next;
    curr->next=NULL;
    delete curr;

   }
    
}


int main(){
Node* node1 = new Node(1);
Node* head = node1;
Node* tail=node1;

print(node1);

// insertAtHead(head,2);
// print(head);
// cout<<endl;

// insertAtHead(head,3);
// print(head);
// cout<<endl;

insertAtTail(tail,2);
print(head);


insertAtTail(tail,3);
print(head);

insertAtPosition(head,tail,3,50);
print(head);

insertAtPosition(head,tail,2,10);
print(head);

deletion(3,head);
print(head);
return 0;
}