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


void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}

Node* getMiddle(Node* head){
    Node* slow =head;
    Node* fast =head->next;

    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow = slow->next;
    }
    return slow;

}

Node* reverse(Node* head){
    Node* curr = head;
    Node* prev= NULL;
    Node* next= NULL;

    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
bool check_palindrome(Node* head){
    if(head->next==NULL){
        return true;
    }

    Node* middle = getMiddle(head);
    Node* temp = middle->next;

    middle->next=reverse(temp);

    Node* head1 = head;
    Node* head2 = middle->next;
    while (head2!=NULL)
    {
        if(head1->data!=head2->data){
            return false;
        }
        head1=head1->next;
        head2=head2->next;
    }
    temp=middle->next;
    middle->next=reverse(temp);
    return true;
}

int main(){

Node* node1 = new Node(1);
Node* head = node1;
insertAtHead(head,2);
insertAtHead(head,3);
insertAtHead(head,4);
insertAtHead(head,2);
insertAtHead(head,1);
// insertAtHead(head,6);

print(head);

if(check_palindrome(head)){
    cout<<"It's a palindromic linklist"<<endl;
}
else{
    cout<<"It's not a palindromic linklist"<<endl;
}

return 0;
}