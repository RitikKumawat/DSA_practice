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


Node* reverse(Node* head){
    Node* curr =head;
    Node* next=NULL;
    Node* prev=NULL;

    while(curr!=NULL){
        next = curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

void insertAtTail(Node* &head, Node* &tail, int val){
    Node* temp = new Node(val);
    if(head==NULL)
    {
        head=temp;
        tail=temp;
        return;
    }
    else{
        tail->next=temp;
        tail=temp;
        return;
    }

}


Node* add(Node* first, Node* second){
    int carry=0;
    Node* anshead = NULL;
    Node* anstail = NULL;

    while(first!=NULL || second!=NULL || carry!=0){
        int val1=0;
        if(first!=NULL)
            val1 = first->data;
        int val2=0;
        if(second!=NULL)
            val2 = second->data;

        int sum = carry + val1 + val2;
        int digit = sum%10;
        
        
        insertAtTail(anshead,anstail,digit);
        int carry = sum/10;

        if(first!=NULL){
            first=  first->next;
        }
        if(second!=NULL){
            second=second->next;
        }
    }
    return anshead;

}

Node* addTwoList(Node* first, Node* second){
    first = reverse(first);
    second = reverse(second);
    
    Node* ans = add(first,second);

    ans = reverse(ans);
    return ans;
}

int main(){

Node* first = new Node(4);
Node* head1 =  first;
insertAtHead(head1,3);

Node* second = new Node(0);
Node* head2 = second;
insertAtHead(head2,3);
insertAtHead(head2,2);

print(head1);
print(head2);

Node* ans =  addTwoList(first,second);

print(ans);
return 0;
}