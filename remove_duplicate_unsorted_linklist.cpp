#include<iostream>
#include<map>

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

Node* remove_Duplicate_unsorted(Node* head){
    if(head==NULL)
        return NULL;
    Node* curr=head;

    while(curr!=NULL){
        Node* temp = curr;
        while(temp!=NULL){
            if((curr->next!=NULL&& temp->next!=NULL)&& (curr->data == temp->next->data) ){
                Node* to_delete = temp->next;
                temp->next=temp->next->next;
                delete to_delete;
            }
            else{
                temp=temp->next;
            }
        }
        curr=curr->next;

    }
    return head;
}

Node* removeDuplicate_optimized(Node* head){
    if(head==NULL)
        return NULL;

    map<int,bool> visited;
    Node* curr = head;
    Node* prev = NULL;
    
    while (curr!=NULL)
    {
        int val = curr->data;
        if(visited[val]){
            
            prev->next=curr->next;
            
            delete curr;
            curr=prev->next;
        }
        else{
            
        visited[val]=true;
        prev=curr;
        curr=curr->next;
        }
    }
    return head;
    
}

int main(){
Node* node1 = new Node(1);
Node* head = node1;

insertAtHead(head,2);
insertAtHead(head,4);
insertAtHead(head,2);
insertAtHead(head,4);
insertAtHead(head,4);

print(head);

// Node* ans = remove_Duplicate_unsorted(head);
// print(ans);

Node * ans = removeDuplicate_optimized(head);
print(ans);
return 0;
}