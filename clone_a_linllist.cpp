#include<iostream>
#include<unordered_map>


using namespace std;


class Node{
    public:
        int data;
        Node* next;
        Node* random;

        Node(int val){
            data=val;
            next=NULL;
        }
};


void insertATTail(Node* &head,Node* &tail, int val){
    Node* newNode = new Node(val);
    if(head==NULL){
        head=newNode;
        tail=newNode;
        return;
    }
    else{
        tail->next=newNode;
        tail=newNode;
    }
}

void print(Node* head){
    Node* temp=head;
    if(head==NULL){
        cout<<"Empty linklist"<<endl;
    }
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }cout<<"NULL"<<endl;
}

Node* cloneLinkList(Node* head){
    Node* cloneHead=NULL;
    Node* cloneTail=NULL;

    Node* temp=head;
    while(temp!=NULL){
        insertATTail(cloneHead,cloneTail,temp->data);
        temp=temp->next;
    }
    unordered_map<Node*,Node*> mapping;
    temp=head;
    Node* temp2=cloneHead;
    while(temp!=NULL){
        mapping[temp] = temp2;
        temp=temp->next;
        temp2=temp2->next;
    }
    temp=head;
    temp2=cloneHead;
    while(temp!=NULL){
        temp2->random = mapping[temp->random];
        temp=temp->next;
        temp2=temp2->next;
    }
    return cloneHead;

}

void Print_random(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->random;
    } cout<<"NULL"<<endl;
}

int main(){
Node* n1 = new Node(3);
Node* n2 = new Node(5);
Node* n3 = new Node(7);
Node* n4 = new Node(9);
Node* n5 = new Node(11);

Node* head=n1;
n1->next=n2;
n2->next=n3;
n3->next=n4;
n4->next=n5;

n1->random=n3;
n2->random=n1;
n3->random=n5;
n4->random=n1;
n5->random=NULL;
print(head);

Node* ans = cloneLinkList(head);

print(ans);


Print_random(ans);




return 0;
}