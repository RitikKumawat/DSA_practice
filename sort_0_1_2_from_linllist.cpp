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

Node* sortList(Node* head){    //Approach 1
    int zerocount=0;
    int onecount=0;
    int twocount=0;

    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==0){
            zerocount++;
        }
        else if(temp->data==1){
            onecount++;
        }
        else if(temp->data==2){
            twocount++;
        }
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        if(zerocount!=0){
            temp->data=0;
            zerocount--;
        }
        else if(onecount!=0){
            temp->data=1;
            onecount--;
        }
        else if(twocount!=0){
            temp->data=2;
            twocount--;
        }
        temp=temp->next;
    }

    return head;
}

void insertAtTail(Node* &tail, Node* curr){
    tail->next=curr;
    tail=curr;
}
Node* sortAll(Node* head){     // Approach 2
    Node* zerohead = new Node(-1);
    Node* zerotail = zerohead;

    Node* onehead = new Node(-1);
    Node* onetail = onehead;
    
    Node* twohead = new Node(-1);
    Node* twotail = twohead;

    Node* curr = head;
    while(curr!=NULL){
        int val = curr->data;
        if(val==0){
            insertAtTail(zerotail,curr);
        }
        else if(val==1){
            insertAtTail(onetail,curr);
        }
        if(val==2){
            insertAtTail(twotail,curr);
        }
        curr=curr->next;
    }

    if(onehead->next!=NULL){
        zerotail->next=onehead->next;
    }
    else{
        zerotail->next=twohead->next;
    }
    onetail->next=twohead->next;
    twotail->next=NULL;

    head=zerohead->next;

    delete zerohead;
    delete onehead;
    delete twohead;

    return head;

}

int main(){

Node* node1 = new Node(2);
Node* head = node1;

insertAtHead(head,0);
insertAtHead(head,1);
insertAtHead(head,2);
insertAtHead(head,1);
print(head);

// Node* ans = sortList(head);
// print(ans);

Node* ans1 =  sortAll(head);
print(ans1);
return 0;
}