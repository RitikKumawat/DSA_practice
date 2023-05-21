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

Node* removeDuplicates_sorted(Node* head){
    if(head==NULL)
        return NULL;
    Node* curr = head;

    while(curr!=NULL){
        if( (curr->next!=NULL) && (curr->data == curr->next->data) ){
            Node* todelete = curr->next;
            curr->next = curr->next->next;
            delete todelete;
        }
        else{
            curr=curr->next;
        }
    }
    return head;
}

int main(){

Node* node1 = new Node(4);
Node* head = node1;
insertAtHead(head,3);
insertAtHead(head,3);
insertAtHead(head,3);
insertAtHead(head,3);
insertAtHead(head,2);
insertAtHead(head,2);
insertAtHead(head,1);

print(head);


Node* ans = removeDuplicates_sorted(head);
print(ans);

return 0;
}